/*********************                                                        */
/** options.h
 **
 ** Copyright 2011-2014  New York University and The University of Iowa,
 ** and as below.
 **
 ** This file automatically generated by:
 **
 **     /home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/mkoptions /home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.h ../theory/idl/options.h
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
/*! \file base_options_template.h
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

#include "cvc4_public.h"

#ifndef __CVC4__OPTIONS__IDL_H
#define __CVC4__OPTIONS__IDL_H

#include "options/options.h"


#line 26 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.h"

#define CVC4_OPTIONS__IDL__FOR_OPTION_HOLDER \
  idlRewriteEq__option_t::type idlRewriteEq; \
  bool idlRewriteEq__setByUser__;

#line 30 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.h"

namespace CVC4 {

namespace options {


#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/idl/options"
extern struct CVC4_PUBLIC idlRewriteEq__option_t { typedef bool type; type operator()() const; bool wasSetByUser() const; void set(const type& v); } idlRewriteEq CVC4_PUBLIC;

#line 38 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.h"

}/* CVC4::options namespace */


#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/idl/options"
template <> void Options::set(options::idlRewriteEq__option_t, const options::idlRewriteEq__option_t::type& x);
#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/idl/options"
template <> const options::idlRewriteEq__option_t::type& Options::operator[](options::idlRewriteEq__option_t) const;
#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/idl/options"
template <> bool Options::wasSetByUser(options::idlRewriteEq__option_t) const;
#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/idl/options"
template <> void Options::assignBool(options::idlRewriteEq__option_t, std::string option, bool value, SmtEngine* smt);

#line 44 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.h"

namespace options {


#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/idl/options"
inline idlRewriteEq__option_t::type idlRewriteEq__option_t::operator()() const { return Options::current()[*this]; }
#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/idl/options"
inline bool idlRewriteEq__option_t::wasSetByUser() const { return Options::current().wasSetByUser(*this); }
#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../theory/idl/options"
inline void idlRewriteEq__option_t::set(const idlRewriteEq__option_t::type& v) { Options::current().set(*this, v); }

#line 50 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.h"

}/* CVC4::options namespace */

}/* CVC4 namespace */

#endif /* __CVC4__OPTIONS__IDL_H */
