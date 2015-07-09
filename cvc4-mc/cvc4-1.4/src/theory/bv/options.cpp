/*********************                                                        */
/** options.cpp
 **
 ** Copyright 2011-2014  New York University and The University of Iowa,
 ** and as below.
 **
 ** This file automatically generated by:
 **
 **     /home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/mkoptions /home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.cpp ../theory/bv/options.cpp
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


#line 10 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> void Options::set(options::bitblastMode__option_t, const options::bitblastMode__option_t::type& x) { d_holder->bitblastMode = x; }
#line 10 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bitblastMode__option_t::type& Options::operator[](options::bitblastMode__option_t) const { return d_holder->bitblastMode; }
#line 10 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bitblastMode__option_t) const { return d_holder->bitblastMode__setByUser__; }
#line 15 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> void Options::set(options::bitvectorAig__option_t, const options::bitvectorAig__option_t::type& x) { d_holder->bitvectorAig = x; }
#line 15 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bitvectorAig__option_t::type& Options::operator[](options::bitvectorAig__option_t) const { return d_holder->bitvectorAig; }
#line 15 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bitvectorAig__option_t) const { return d_holder->bitvectorAig__setByUser__; }
#line 18 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> void Options::set(options::bitvectorAigSimplifications__option_t, const options::bitvectorAigSimplifications__option_t::type& x) { d_holder->bitvectorAigSimplifications = x; }
#line 18 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bitvectorAigSimplifications__option_t::type& Options::operator[](options::bitvectorAigSimplifications__option_t) const { return d_holder->bitvectorAigSimplifications; }
#line 18 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bitvectorAigSimplifications__option_t) const { return d_holder->bitvectorAigSimplifications__setByUser__; }
#line 23 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> void Options::set(options::bitvectorPropagate__option_t, const options::bitvectorPropagate__option_t::type& x) { d_holder->bitvectorPropagate = x; }
#line 23 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bitvectorPropagate__option_t::type& Options::operator[](options::bitvectorPropagate__option_t) const { return d_holder->bitvectorPropagate; }
#line 23 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bitvectorPropagate__option_t) const { return d_holder->bitvectorPropagate__setByUser__; }
#line 26 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> void Options::set(options::bitvectorEqualitySolver__option_t, const options::bitvectorEqualitySolver__option_t::type& x) { d_holder->bitvectorEqualitySolver = x; }
#line 26 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bitvectorEqualitySolver__option_t::type& Options::operator[](options::bitvectorEqualitySolver__option_t) const { return d_holder->bitvectorEqualitySolver; }
#line 26 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bitvectorEqualitySolver__option_t) const { return d_holder->bitvectorEqualitySolver__setByUser__; }
#line 29 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> void Options::set(options::bitvectorEqualitySlicer__option_t, const options::bitvectorEqualitySlicer__option_t::type& x) { d_holder->bitvectorEqualitySlicer = x; }
#line 29 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bitvectorEqualitySlicer__option_t::type& Options::operator[](options::bitvectorEqualitySlicer__option_t) const { return d_holder->bitvectorEqualitySlicer; }
#line 29 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bitvectorEqualitySlicer__option_t) const { return d_holder->bitvectorEqualitySlicer__setByUser__; }
#line 32 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> void Options::set(options::bitvectorInequalitySolver__option_t, const options::bitvectorInequalitySolver__option_t::type& x) { d_holder->bitvectorInequalitySolver = x; }
#line 32 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bitvectorInequalitySolver__option_t::type& Options::operator[](options::bitvectorInequalitySolver__option_t) const { return d_holder->bitvectorInequalitySolver; }
#line 32 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bitvectorInequalitySolver__option_t) const { return d_holder->bitvectorInequalitySolver__setByUser__; }
#line 35 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> void Options::set(options::bitvectorAlgebraicSolver__option_t, const options::bitvectorAlgebraicSolver__option_t::type& x) { d_holder->bitvectorAlgebraicSolver = x; }
#line 35 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bitvectorAlgebraicSolver__option_t::type& Options::operator[](options::bitvectorAlgebraicSolver__option_t) const { return d_holder->bitvectorAlgebraicSolver; }
#line 35 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bitvectorAlgebraicSolver__option_t) const { return d_holder->bitvectorAlgebraicSolver__setByUser__; }
#line 38 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> void Options::set(options::bitvectorAlgebraicBudget__option_t, const options::bitvectorAlgebraicBudget__option_t::type& x) { d_holder->bitvectorAlgebraicBudget = x; }
#line 38 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bitvectorAlgebraicBudget__option_t::type& Options::operator[](options::bitvectorAlgebraicBudget__option_t) const { return d_holder->bitvectorAlgebraicBudget; }
#line 38 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bitvectorAlgebraicBudget__option_t) const { return d_holder->bitvectorAlgebraicBudget__setByUser__; }
#line 43 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> void Options::set(options::bitvectorToBool__option_t, const options::bitvectorToBool__option_t::type& x) { d_holder->bitvectorToBool = x; }
#line 43 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bitvectorToBool__option_t::type& Options::operator[](options::bitvectorToBool__option_t) const { return d_holder->bitvectorToBool; }
#line 43 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bitvectorToBool__option_t) const { return d_holder->bitvectorToBool__setByUser__; }
#line 46 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bitvectorDivByZeroConst__option_t::type& Options::operator[](options::bitvectorDivByZeroConst__option_t) const { return d_holder->bitvectorDivByZeroConst; }
#line 46 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bitvectorDivByZeroConst__option_t) const { return d_holder->bitvectorDivByZeroConst__setByUser__; }
#line 49 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> void Options::set(options::bvAbstraction__option_t, const options::bvAbstraction__option_t::type& x) { d_holder->bvAbstraction = x; }
#line 49 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bvAbstraction__option_t::type& Options::operator[](options::bvAbstraction__option_t) const { return d_holder->bvAbstraction; }
#line 49 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bvAbstraction__option_t) const { return d_holder->bvAbstraction__setByUser__; }
#line 52 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> void Options::set(options::skolemizeArguments__option_t, const options::skolemizeArguments__option_t::type& x) { d_holder->skolemizeArguments = x; }
#line 52 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::skolemizeArguments__option_t::type& Options::operator[](options::skolemizeArguments__option_t) const { return d_holder->skolemizeArguments; }
#line 52 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::skolemizeArguments__option_t) const { return d_holder->skolemizeArguments__setByUser__; }
#line 55 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bvNumFunc__option_t::type& Options::operator[](options::bvNumFunc__option_t) const { return d_holder->bvNumFunc; }
#line 55 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bvNumFunc__option_t) const { return d_holder->bvNumFunc__setByUser__; }
#line 58 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> void Options::set(options::bvEagerExplanations__option_t, const options::bvEagerExplanations__option_t::type& x) { d_holder->bvEagerExplanations = x; }
#line 58 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bvEagerExplanations__option_t::type& Options::operator[](options::bvEagerExplanations__option_t) const { return d_holder->bvEagerExplanations; }
#line 58 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bvEagerExplanations__option_t) const { return d_holder->bvEagerExplanations__setByUser__; }
#line 61 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bitvectorQuickXplain__option_t::type& Options::operator[](options::bitvectorQuickXplain__option_t) const { return d_holder->bitvectorQuickXplain; }
#line 61 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bitvectorQuickXplain__option_t) const { return d_holder->bitvectorQuickXplain__setByUser__; }
#line 64 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> const options::bvIntroducePow2__option_t::type& Options::operator[](options::bvIntroducePow2__option_t) const { return d_holder->bvIntroducePow2; }
#line 64 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
template <> bool Options::wasSetByUser(options::bvIntroducePow2__option_t) const { return d_holder->bvIntroducePow2__setByUser__; }

#line 24 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.cpp"

namespace options {


#line 10 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bitblastMode__option_t bitblastMode;
#line 15 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bitvectorAig__option_t bitvectorAig;
#line 18 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bitvectorAigSimplifications__option_t bitvectorAigSimplifications;
#line 23 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bitvectorPropagate__option_t bitvectorPropagate;
#line 26 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bitvectorEqualitySolver__option_t bitvectorEqualitySolver;
#line 29 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bitvectorEqualitySlicer__option_t bitvectorEqualitySlicer;
#line 32 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bitvectorInequalitySolver__option_t bitvectorInequalitySolver;
#line 35 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bitvectorAlgebraicSolver__option_t bitvectorAlgebraicSolver;
#line 38 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bitvectorAlgebraicBudget__option_t bitvectorAlgebraicBudget;
#line 43 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bitvectorToBool__option_t bitvectorToBool;
#line 46 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bitvectorDivByZeroConst__option_t bitvectorDivByZeroConst;
#line 49 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bvAbstraction__option_t bvAbstraction;
#line 52 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct skolemizeArguments__option_t skolemizeArguments;
#line 55 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bvNumFunc__option_t bvNumFunc;
#line 58 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bvEagerExplanations__option_t bvEagerExplanations;
#line 61 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bitvectorQuickXplain__option_t bitvectorQuickXplain;
#line 64 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/bv/options"
struct bvIntroducePow2__option_t bvIntroducePow2;

#line 30 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.cpp"

}/* CVC4::options namespace */

}/* CVC4 namespace */