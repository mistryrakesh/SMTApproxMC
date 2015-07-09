/*********************                                                        */
/** options.h
 **
 ** Copyright 2011-2014  New York University and The University of Iowa,
 ** and as below.
 **
 ** This file automatically generated by:
 **
 **     /home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/mkoptions /home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.h ../parser/options.h
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

#ifndef __CVC4__OPTIONS__PARSER_H
#define __CVC4__OPTIONS__PARSER_H

#include "options/options.h"


#line 26 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.h"

#define CVC4_OPTIONS__PARSER__FOR_OPTION_HOLDER \
  strictParsing__option_t::type strictParsing; \
  bool strictParsing__setByUser__; \
  memoryMap__option_t::type memoryMap; \
  bool memoryMap__setByUser__; \
  semanticChecks__option_t::type semanticChecks; \
  bool semanticChecks__setByUser__; \
  filesystemAccess__option_t::type filesystemAccess; \
  bool filesystemAccess__setByUser__;

#line 30 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.h"

namespace CVC4 {

namespace options {


#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
extern struct CVC4_PUBLIC strictParsing__option_t { typedef bool type; type operator()() const; bool wasSetByUser() const; } strictParsing CVC4_PUBLIC;
#line 11 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
extern struct CVC4_PUBLIC memoryMap__option_t { typedef bool type; type operator()() const; bool wasSetByUser() const; } memoryMap CVC4_PUBLIC;
#line 14 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
extern struct CVC4_PUBLIC semanticChecks__option_t { typedef bool type; type operator()() const; bool wasSetByUser() const; } semanticChecks CVC4_PUBLIC;
#line 28 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
extern struct CVC4_PUBLIC filesystemAccess__option_t { typedef bool type; type operator()() const; bool wasSetByUser() const; } filesystemAccess CVC4_PUBLIC;

#line 38 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.h"

}/* CVC4::options namespace */


#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
template <> const options::strictParsing__option_t::type& Options::operator[](options::strictParsing__option_t) const;
#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
template <> bool Options::wasSetByUser(options::strictParsing__option_t) const;
#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
template <> void Options::assignBool(options::strictParsing__option_t, std::string option, bool value, SmtEngine* smt);
#line 11 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
template <> const options::memoryMap__option_t::type& Options::operator[](options::memoryMap__option_t) const;
#line 11 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
template <> bool Options::wasSetByUser(options::memoryMap__option_t) const;
#line 11 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
template <> void Options::assignBool(options::memoryMap__option_t, std::string option, bool value, SmtEngine* smt);
#line 14 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
template <> const options::semanticChecks__option_t::type& Options::operator[](options::semanticChecks__option_t) const;
#line 14 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
template <> bool Options::wasSetByUser(options::semanticChecks__option_t) const;
#line 14 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
template <> void Options::assignBool(options::semanticChecks__option_t, std::string option, bool value, SmtEngine* smt);
#line 28 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
template <> const options::filesystemAccess__option_t::type& Options::operator[](options::filesystemAccess__option_t) const;
#line 28 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
template <> bool Options::wasSetByUser(options::filesystemAccess__option_t) const;
#line 28 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
template <> void Options::assignBool(options::filesystemAccess__option_t, std::string option, bool value, SmtEngine* smt);

#line 44 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.h"

namespace options {


#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
inline strictParsing__option_t::type strictParsing__option_t::operator()() const { return Options::current()[*this]; }
#line 8 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
inline bool strictParsing__option_t::wasSetByUser() const { return Options::current().wasSetByUser(*this); }

#line 11 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
inline memoryMap__option_t::type memoryMap__option_t::operator()() const { return Options::current()[*this]; }
#line 11 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
inline bool memoryMap__option_t::wasSetByUser() const { return Options::current().wasSetByUser(*this); }

#line 14 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
inline semanticChecks__option_t::type semanticChecks__option_t::operator()() const { return Options::current()[*this]; }
#line 14 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
inline bool semanticChecks__option_t::wasSetByUser() const { return Options::current().wasSetByUser(*this); }

#line 28 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
inline filesystemAccess__option_t::type filesystemAccess__option_t::operator()() const { return Options::current()[*this]; }
#line 28 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/../parser/options"
inline bool filesystemAccess__option_t::wasSetByUser() const { return Options::current().wasSetByUser(*this); }

#line 50 "/home/mdeters/cvc4/builds/x86_64-unknown-linux-gnu/production/../../../src/options/base_options_template.h"

}/* CVC4::options namespace */

}/* CVC4 namespace */

#endif /* __CVC4__OPTIONS__PARSER_H */
