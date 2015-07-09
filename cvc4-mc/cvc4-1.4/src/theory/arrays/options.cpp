/*********************                                                        */
/** options.cpp
 **
 ** Copyright 2011-2014  New York University and The University of Iowa,
 ** and as below.
 **
 ** This file automatically generated by:
 **
 **     /home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/mkoptions /home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.cpp ../theory/arrays/options.cpp
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


#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
template <> void Options::set(options::arraysOptimizeLinear__option_t, const options::arraysOptimizeLinear__option_t::type& x) { d_holder->arraysOptimizeLinear = x; }
#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
template <> const options::arraysOptimizeLinear__option_t::type& Options::operator[](options::arraysOptimizeLinear__option_t) const { return d_holder->arraysOptimizeLinear; }
#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
template <> bool Options::wasSetByUser(options::arraysOptimizeLinear__option_t) const { return d_holder->arraysOptimizeLinear__setByUser__; }
#line 11 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
template <> void Options::set(options::arraysLazyRIntro1__option_t, const options::arraysLazyRIntro1__option_t::type& x) { d_holder->arraysLazyRIntro1 = x; }
#line 11 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
template <> const options::arraysLazyRIntro1__option_t::type& Options::operator[](options::arraysLazyRIntro1__option_t) const { return d_holder->arraysLazyRIntro1; }
#line 11 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
template <> bool Options::wasSetByUser(options::arraysLazyRIntro1__option_t) const { return d_holder->arraysLazyRIntro1__setByUser__; }
#line 14 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
template <> void Options::set(options::arraysModelBased__option_t, const options::arraysModelBased__option_t::type& x) { d_holder->arraysModelBased = x; }
#line 14 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
template <> const options::arraysModelBased__option_t::type& Options::operator[](options::arraysModelBased__option_t) const { return d_holder->arraysModelBased; }
#line 14 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
template <> bool Options::wasSetByUser(options::arraysModelBased__option_t) const { return d_holder->arraysModelBased__setByUser__; }
#line 17 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
template <> void Options::set(options::arraysEagerIndexSplitting__option_t, const options::arraysEagerIndexSplitting__option_t::type& x) { d_holder->arraysEagerIndexSplitting = x; }
#line 17 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
template <> const options::arraysEagerIndexSplitting__option_t::type& Options::operator[](options::arraysEagerIndexSplitting__option_t) const { return d_holder->arraysEagerIndexSplitting; }
#line 17 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
template <> bool Options::wasSetByUser(options::arraysEagerIndexSplitting__option_t) const { return d_holder->arraysEagerIndexSplitting__setByUser__; }
#line 20 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
template <> void Options::set(options::arraysEagerLemmas__option_t, const options::arraysEagerLemmas__option_t::type& x) { d_holder->arraysEagerLemmas = x; }
#line 20 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
template <> const options::arraysEagerLemmas__option_t::type& Options::operator[](options::arraysEagerLemmas__option_t) const { return d_holder->arraysEagerLemmas; }
#line 20 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
template <> bool Options::wasSetByUser(options::arraysEagerLemmas__option_t) const { return d_holder->arraysEagerLemmas__setByUser__; }

#line 24 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.cpp"

namespace options {


#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
struct arraysOptimizeLinear__option_t arraysOptimizeLinear;
#line 11 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
struct arraysLazyRIntro1__option_t arraysLazyRIntro1;
#line 14 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
struct arraysModelBased__option_t arraysModelBased;
#line 17 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
struct arraysEagerIndexSplitting__option_t arraysEagerIndexSplitting;
#line 20 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/arrays/options"
struct arraysEagerLemmas__option_t arraysEagerLemmas;

#line 30 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.cpp"

}/* CVC4::options namespace */

}/* CVC4 namespace */
