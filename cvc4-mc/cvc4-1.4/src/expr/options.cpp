/*********************                                                        */
/** options.cpp
 **
 ** Copyright 2011-2014  New York University and The University of Iowa,
 ** and as below.
 **
 ** This file automatically generated by:
 **
 **     /home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/mkoptions /home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.cpp ../expr/options.cpp
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


#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../expr/options"
template <> const options::defaultExprDepth__option_t::type& Options::operator[](options::defaultExprDepth__option_t) const { return d_holder->defaultExprDepth; }
#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../expr/options"
template <> bool Options::wasSetByUser(options::defaultExprDepth__option_t) const { return d_holder->defaultExprDepth__setByUser__; }
#line 12 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../expr/options"
template <> const options::defaultDagThresh__option_t::type& Options::operator[](options::defaultDagThresh__option_t) const { return d_holder->defaultDagThresh; }
#line 12 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../expr/options"
template <> bool Options::wasSetByUser(options::defaultDagThresh__option_t) const { return d_holder->defaultDagThresh__setByUser__; }
#line 20 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../expr/options"
template <> const options::earlyTypeChecking__option_t::type& Options::operator[](options::earlyTypeChecking__option_t) const { return d_holder->earlyTypeChecking; }
#line 20 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../expr/options"
template <> bool Options::wasSetByUser(options::earlyTypeChecking__option_t) const { return d_holder->earlyTypeChecking__setByUser__; }
#line 26 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../expr/options"
template <> const options::typeChecking__option_t::type& Options::operator[](options::typeChecking__option_t) const { return d_holder->typeChecking; }
#line 26 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../expr/options"
template <> bool Options::wasSetByUser(options::typeChecking__option_t) const { return d_holder->typeChecking__setByUser__; }
#line 29 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../expr/options"
template <> const options::biasedITERemoval__option_t::type& Options::operator[](options::biasedITERemoval__option_t) const { return d_holder->biasedITERemoval; }
#line 29 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../expr/options"
template <> bool Options::wasSetByUser(options::biasedITERemoval__option_t) const { return d_holder->biasedITERemoval__setByUser__; }

#line 24 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.cpp"

namespace options {


#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../expr/options"
struct defaultExprDepth__option_t defaultExprDepth;
#line 12 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../expr/options"
struct defaultDagThresh__option_t defaultDagThresh;
#line 20 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../expr/options"
struct earlyTypeChecking__option_t earlyTypeChecking;
#line 26 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../expr/options"
struct typeChecking__option_t typeChecking;
#line 29 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../expr/options"
struct biasedITERemoval__option_t biasedITERemoval;

#line 30 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.cpp"

}/* CVC4::options namespace */

}/* CVC4 namespace */
