/*********************                                                        */
/** options.cpp
 **
 ** Copyright 2011-2014  New York University and The University of Iowa,
 ** and as below.
 **
 ** This file automatically generated by:
 **
 **     /home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/mkoptions /home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.cpp ../prop/options.cpp
 **
 ** for the CVC4 project.
 **/

/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */

/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */
/* THIS FILE IS AUTOMATICALLY GENERATED, DO NOT EDIT ! */

/* Edit the template file instead.                     */

/*********************                                                        */
/*! \file base_options_template.cpp
 ** \verbatim
 ** Original author: Morgan Deters
 ** Major contributors: none
 ** Minor contributors (to current version): none
 ** This file is part of the CVC4 project.
 ** Copyright (c) 2009-2014  New York University and The University of Iowa
 ** See the file COPYING in the top-level source directory for licensing
 ** information.\endverbatim
 **
 ** \brief Contains code for handling command-line options.
 **
 ** Contains code for handling command-line options
 **/

#include "options/options_holder.h"

namespace CVC4 {


#line 11 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> const options::satRandomFreq__option_t::type& Options::operator[](options::satRandomFreq__option_t) const { return d_holder->satRandomFreq; }
#line 11 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> bool Options::wasSetByUser(options::satRandomFreq__option_t) const { return d_holder->satRandomFreq__setByUser__; }
#line 13 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> void Options::set(options::satRandomSeed__option_t, const options::satRandomSeed__option_t::type& x) { d_holder->satRandomSeed = x; }
#line 13 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> const options::satRandomSeed__option_t::type& Options::operator[](options::satRandomSeed__option_t) const { return d_holder->satRandomSeed; }
#line 13 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> bool Options::wasSetByUser(options::satRandomSeed__option_t) const { return d_holder->satRandomSeed__setByUser__; }
#line 16 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> void Options::set(options::satVarDecay__option_t, const options::satVarDecay__option_t::type& x) { d_holder->satVarDecay = x; }
#line 16 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> const options::satVarDecay__option_t::type& Options::operator[](options::satVarDecay__option_t) const { return d_holder->satVarDecay; }
#line 16 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> bool Options::wasSetByUser(options::satVarDecay__option_t) const { return d_holder->satVarDecay__setByUser__; }
#line 18 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> void Options::set(options::satClauseDecay__option_t, const options::satClauseDecay__option_t::type& x) { d_holder->satClauseDecay = x; }
#line 18 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> const options::satClauseDecay__option_t::type& Options::operator[](options::satClauseDecay__option_t) const { return d_holder->satClauseDecay; }
#line 18 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> bool Options::wasSetByUser(options::satClauseDecay__option_t) const { return d_holder->satClauseDecay__setByUser__; }
#line 20 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> const options::satRestartFirst__option_t::type& Options::operator[](options::satRestartFirst__option_t) const { return d_holder->satRestartFirst; }
#line 20 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> bool Options::wasSetByUser(options::satRestartFirst__option_t) const { return d_holder->satRestartFirst__setByUser__; }
#line 22 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> const options::satRestartInc__option_t::type& Options::operator[](options::satRestartInc__option_t) const { return d_holder->satRestartInc; }
#line 22 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> bool Options::wasSetByUser(options::satRestartInc__option_t) const { return d_holder->satRestartInc__setByUser__; }
#line 25 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> const options::sat_refine_conflicts__option_t::type& Options::operator[](options::sat_refine_conflicts__option_t) const { return d_holder->sat_refine_conflicts; }
#line 25 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> bool Options::wasSetByUser(options::sat_refine_conflicts__option_t) const { return d_holder->sat_refine_conflicts__setByUser__; }
#line 28 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> void Options::set(options::minisatUseElim__option_t, const options::minisatUseElim__option_t::type& x) { d_holder->minisatUseElim = x; }
#line 28 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> const options::minisatUseElim__option_t::type& Options::operator[](options::minisatUseElim__option_t) const { return d_holder->minisatUseElim; }
#line 28 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> bool Options::wasSetByUser(options::minisatUseElim__option_t) const { return d_holder->minisatUseElim__setByUser__; }
#line 31 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> const options::minisatDumpDimacs__option_t::type& Options::operator[](options::minisatDumpDimacs__option_t) const { return d_holder->minisatDumpDimacs; }
#line 31 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
template <> bool Options::wasSetByUser(options::minisatDumpDimacs__option_t) const { return d_holder->minisatDumpDimacs__setByUser__; }

#line 24 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.cpp"

namespace options {


#line 11 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
struct satRandomFreq__option_t satRandomFreq;
#line 13 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
struct satRandomSeed__option_t satRandomSeed;
#line 16 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
struct satVarDecay__option_t satVarDecay;
#line 18 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
struct satClauseDecay__option_t satClauseDecay;
#line 20 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
struct satRestartFirst__option_t satRestartFirst;
#line 22 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
struct satRestartInc__option_t satRestartInc;
#line 25 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
struct sat_refine_conflicts__option_t sat_refine_conflicts;
#line 28 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
struct minisatUseElim__option_t minisatUseElim;
#line 31 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../prop/options"
struct minisatDumpDimacs__option_t minisatDumpDimacs;

#line 30 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.cpp"

}/* CVC4::options namespace */

}/* CVC4 namespace */