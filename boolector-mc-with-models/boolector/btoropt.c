/*  Boolector: Satisfiablity Modulo Theories (SMT) solver.
 *
 *  Copyright (C) 2014-2015 Aina Niemetz.
 *  Copyright (C) 2014-2015 Mathias Preiner.
 *
 *  All rights reserved.
 *
 *  This file is part of Boolector.
 *  See COPYING for more information on using this software.
 */

#include <ctype.h>
#include "boolector.h"
#include "btoropt.h"
#include "btorcore.h"
#include "btortrapi.h"
#include "btorlog.h"
#include "utils/btoriter.h"
#include "btormodel.h"


static char *
getenv_value (const char * lname)
{
  char uname[40];
  size_t i, j;

  assert (strlen (lname) + 4 + 1 < sizeof (uname));
  uname[0] = 'B'; uname[1] = 'T'; uname[2] = 'O'; uname[3] = 'R';
  for (i = 4, j = 0; i < sizeof (uname); i++, j++)
    {
      if (lname[j] == '_') 
        {
          i -= 1;
          continue;
        }
      uname[i] = toupper (lname[j]);
    }

  return getenv (uname);
}

static void
set_opt_values (BtorOpt * opt,
                int internal,
                char * shrt, 
                char * lng, 
                int val, 
                int min, 
                int max, 
                char * desc)
{
  assert (opt);
  assert (min <= val);
  assert (max == -1 || val <= max);

  opt->internal = internal;
  opt->shrt = shrt;
  opt->lng = lng;
  opt->val = val;
  opt->dflt = val;
  opt->min = min;
  opt->max = max;
  opt->desc = desc;
}

#define BTOR_SET_OPT(LNG,VAL) \
  do { \
    boolector_set_opt (btor, #LNG, VAL); \
  } while (0)

#define BTOR_SET_OPT_INTL(LNG,VAL) \
  do { \
    btor_set_opt (btor, #LNG, VAL); \
  } while (0)

#define BTOR_OPT(SHRT,LNG,VAL,MIN,MAX,DESC) \
  do { \
    set_opt_values ( \
        &btor->options.LNG, 0, SHRT, #LNG, VAL, MIN, MAX, DESC); \
    valstr = getenv_value (#LNG); \
    if (valstr == NULL) break; \
    val = atoi (valstr); \
    if (val < btor->options.LNG.min) val = btor->options.LNG.min; \
    if (val > btor->options.LNG.max) val = btor->options.LNG.max; \
    if (val == btor->options.LNG.val) break; \
    BTOR_SET_OPT (LNG, val); \
  } while (0)

#define BTOR_OPT_INTL(SHRT,LNG,VAL,MIN,MAX,DESC) \
  do { \
    set_opt_values ( \
        &btor->options.LNG, 1, SHRT, #LNG, VAL, MIN, MAX, DESC); \
    valstr = getenv_value (#LNG); \
    if (valstr == NULL) break; \
    val = atoi (valstr); \
    if (val < btor->options.LNG.min) val = btor->options.LNG.min; \
    if (val > btor->options.LNG.max) val = btor->options.LNG.max; \
    if (val == btor->options.LNG.val) break; \
    BTOR_SET_OPT_INTL (LNG, val); \
  } while (0)

void
btor_init_opts (Btor * btor) 
{
  int val;
  char *valstr;

  BTOR_OPT ("m", model_gen, 0, 0, 2,
            "print model for satisfiable instances"); 

  BTOR_OPT ("i", incremental, 0, 0, 1,
            "incremental usage (SMT1 only)"); 
  BTOR_OPT ("I", incremental_all, 0, 0, 1,
            "incremental, solve all (SMT1 only)"); 

  BTOR_OPT (0, input_format,
            BTOR_INPUT_FORMAT_DFLT, BTOR_INPUT_FORMAT_MIN,
            BTOR_INPUT_FORMAT_MAX,
            "input file format"); 
  BTOR_OPT (0, output_number_format, 
            BTOR_OUTPUT_BASE_DFLT, BTOR_OUTPUT_BASE_MIN,
            BTOR_OUTPUT_BASE_MAX,
            "output number format"); 
  BTOR_OPT (0, output_format, 
            BTOR_OUTPUT_FORMAT_DFLT, BTOR_OUTPUT_FORMAT_MIN, 
            BTOR_OUTPUT_FORMAT_MAX,
            "output file format");

  BTOR_OPT ("rwl", rewrite_level, 3, 0, 3,
            "rewrite level"); 
  BTOR_OPT (0, rewrite_level_pbr, 1, 0, 3,
            "rewrite level partial beta reduction"); 

  BTOR_OPT ("bra", beta_reduce_all, 0, 0, 1,
            "eagerly eliminate lambda expressions"); 
#ifdef BTOR_ENABLE_BETA_REDUCTION_PROBING
  BTOR_OPT ("pbra", probe_beta_reduce_all, 0, 0, 1,
            "probe -bra until given LOD or SAT limit"); 
  BTOR_OPT (0, pbra_lod_limit, 10, 0, -1,
            "LOD limit (#lemmas) for -pbra"); 
  BTOR_OPT (0, pbra_sat_limit, 55000, 0, -1,
            "SAT limit (#conflicts) for -pbra"); 
  BTOR_OPT (0, pbra_ops_factor, 10, 0, -1,
            "factor by which the size of the red. formula may be greater than "
            "the original formula"); 
#endif

  BTOR_OPT ("dp", dual_prop, 0, 0, 1,
            "dual propagation optimization");
  BTOR_OPT ("ju", just, 0, 0, 1,
            "justification optimization");
  BTOR_OPT (0, just_heuristic,
            BTOR_JUST_HEUR_DFLT, BTOR_JUST_HEUR_MIN, BTOR_JUST_HEUR_MAX,
            "justification heuristic");
#ifndef BTOR_DO_NOT_OPTIMIZE_UNCONSTRAINED
  BTOR_OPT ("uc", ucopt, 0, 0, 1,
            "unconstrained optimization");
#endif
  BTOR_OPT ("ls", lazy_synthesize, 1, 0, 1,
            "lazily synthesize expressions");
  BTOR_OPT ("es", eliminate_slices, 1, 0, 1,
            "eliminate slices on variables");
  BTOR_OPT ("ac", auto_cleanup, 0, 0, 1,
            "auto cleanup on exit"); 
  BTOR_OPT ("p", pretty_print, 1, 0, 1,
            "pretty print when dumping"); 
  BTOR_OPT ("e", exit_codes, 1, 0, 1,
            "use Boolector exit codes"); 
#ifndef NBTORLOG
  BTOR_OPT ("l", loglevel, 0, 0, BTORLOG_LEVEL_MAX,
            "increase loglevel");
#endif
  BTOR_OPT ("v", verbosity, 0, 0, BTOR_VERBOSITY_MAX,
            "increase verbosity");

  BTOR_OPT_INTL (0, simplify_constraints, 1, 0, 1, 0);
  BTOR_OPT_INTL (0, auto_cleanup_internal, 0, 0, 1, 0);
#ifdef BTOR_CHECK_FAILED
  BTOR_OPT_INTL (0, chk_failed_assumptions, 1, 0, 1, 0);
#endif
  BTOR_OPT_INTL (0, incremental_in_depth, 0, 0, 1,
                 "incremental in-depth mode width (SMT1 only)"); 
  BTOR_OPT_INTL (0, incremental_look_ahead, 0, 0, 1,
                 "incremental look-ahead width (SMT1 only)"); 
  BTOR_OPT_INTL (0, incremental_interval, 0, 0, 1,
                 "incremental interval mode width (SMT1 only)"); 
  BTOR_OPT_INTL (0, parse_interactive, 1, 0, 1,
                 "interactive parse mode");
}

#define BTOR_FIRST_OPT(btor) (&(btor)->options.first + 1)
#define BTOR_LAST_OPT(btor) (&(btor)->options.last - 1)

BtorOpt *
btor_get_opt_aux (Btor * btor, const char * name, int skip_internal)
{
  assert (btor);
  assert (name);

  BtorOpt *o;

  for (o = BTOR_FIRST_OPT (btor); o <= BTOR_LAST_OPT (btor); o++)
    if ((o->shrt && !strcmp (o->shrt, name)) 
        || (o->lng && !strcmp (o->lng, name)) )
      {
        if (skip_internal && o->internal) continue;
        return o;
      }

  return 0;
}

BtorOpt *
btor_get_opt (Btor * btor, const char * name)
{
  BtorOpt *o = btor_get_opt_aux (btor, name, 0);
  return o;
}

int
btor_get_opt_val (Btor * btor , const char * name)
{
  return btor_get_opt (btor, name)->val;
}

int
btor_get_opt_min (Btor * btor , const char * name)
{
  return btor_get_opt (btor, name)->min;
}

int
btor_get_opt_max (Btor * btor , const char * name)
{
  return btor_get_opt (btor, name)->max;
}

int
btor_get_opt_dflt (Btor * btor , const char * name)
{
  return btor_get_opt (btor, name)->dflt;
}

const char *
btor_get_opt_shrt (Btor * btor, const char * name)
{
  return (const char *) btor_get_opt (btor, name)->shrt;
}

const char *
btor_get_opt_desc (Btor * btor, const char * name)
{
  return (const char *) btor_get_opt (btor, name)->desc;
}

void
btor_set_opt (Btor * btor, const char * name, int val)
{
  assert (btor);
  assert (name);

  BtorOpt *o;

#ifdef NBTORLOG
  if (!strcmp (name, BTOR_OPT_LOGLEVEL))
    return;
#endif

  o = btor_get_opt (btor, name);
  assert (o);
#ifndef NDEBUG
  int oldval = o->val;
#endif
  if (val > o->max) val = o->max;
  if (val < o->min) val = o->min;
  o->val = val;
  
  if (!strcmp (name, "m") || !strcmp (name, BTOR_OPT_MODEL_GEN))
    {
      if (!val && btor->options.model_gen.val)
        btor_delete_model (btor);
      assert (!val || !btor->options.ucopt.val);
#ifdef BTOR_ENABLE_BETA_REDUCTION_PROBING
      assert (!val || !btor->options.probe_beta_reduce_all.val);
#endif
    }
  else if (!strcmp (name, "i") || !strcmp (name, BTOR_OPT_INCREMENTAL))
    {
      assert (val > 0);
      assert (btor->btor_sat_btor_called == 0);
    }
  else if (!strcmp (name, BTOR_OPT_INCREMENTAL_IN_DEPTH))
    {
      assert (val > 1);
      assert (!btor->options.incremental_look_ahead.val
              && !btor->options.incremental_interval.val);
    }
  else if (!strcmp (name, BTOR_OPT_INCREMENTAL_LOOK_AHEAD))
    {
      assert (val > 1);
      assert (!btor->options.incremental_in_depth.val
              && !btor->options.incremental_interval.val);
    }
  else if (!strcmp (name, BTOR_OPT_INCREMENTAL_INTERVAL))
    {
      assert (val > 1);
      assert (!btor->options.incremental_in_depth.val
              && !btor->options.incremental_look_ahead.val);
    }
  else if (!strcmp (name, "dp") || !strcmp (name, BTOR_OPT_DUAL_PROP))
    {
      assert (!val || !btor->options.just.val);
    }
  else if (!strcmp (name, "ju") || !strcmp (name, BTOR_OPT_JUST))
    {
      assert (!val || !btor->options.dual_prop.val);
    }
  else if (!strcmp (name, "rwl") || !strcmp (name, BTOR_OPT_REWRITE_LEVEL))
    {
      assert (val >= 0 && val <= 3);
      assert (oldval >= 0 && oldval <= 3);
    }
  else if (!strcmp (name, BTOR_OPT_REWRITE_LEVEL_PBR))
    {
      assert (val >= 0 && val <= 3);
      assert (oldval >= 0 && oldval <= 3);
    }
}

const char *
btor_first_opt (Btor * btor)
{
  assert (btor);
  assert (BTOR_FIRST_OPT (btor));
  return (const char *) BTOR_FIRST_OPT (btor)->lng;
}
    
const char *
btor_next_opt (Btor * btor, const char * cur)
{
  assert (btor);
  assert (cur);

  BtorOpt *cur_opt;
  
  cur_opt = btor_get_opt (btor, cur) + 1; 
  /* skip internal options */
  while (cur_opt <= BTOR_LAST_OPT (btor) && cur_opt->internal) cur_opt += 1;
  if (cur_opt > BTOR_LAST_OPT (btor)) return 0;
  return (const char *) cur_opt->lng;
}

