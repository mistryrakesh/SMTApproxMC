/* cvc4autoconfig.h.  Generated from cvc4autoconfig.h.in by configure.  */
/* cvc4autoconfig.h.in.  Generated from configure.ac by autoheader.  */

#ifndef __CVC4__CVC4AUTOCONFIG_H
#define __CVC4__CVC4AUTOCONFIG_H

/* Define to 1 if Boost threading library has support for thread attributes */
#define BOOST_HAS_THREAD_ATTR 0

/* Defined if using the CLN multi-precision arithmetic library. */
/* #undef CVC4_CLN_IMP */

/* Extraversion component of the version of CVC4. */
#define CVC4_EXTRAVERSION ""

/* Defined if using the GMP multi-precision arithmetic library. */
#define CVC4_GMP_IMP /**/

/* Whether CVC4 is built with the (optional) GPLed library dependences. */
#define CVC4_GPL_DEPS 0

/* Major component of the version of CVC4. */
#define CVC4_MAJOR 1

/* Minor component of the version of CVC4. */
#define CVC4_MINOR 4

/* Release component of the version of CVC4. */
#define CVC4_RELEASE 0

/* Full release string for CVC4. */
#define CVC4_RELEASE_STRING "1.4"

/* Defined if the requested minimum BOOST version is satisfied */
#define HAVE_BOOST 1

/* Define to 1 if you have <boost/system/error_code.hpp> */
/* #undef HAVE_BOOST_SYSTEM_ERROR_CODE_HPP */

/* Define to 1 if you have <boost/thread.hpp> */
#define HAVE_BOOST_THREAD_HPP 1

/* Defined to 1 if clock_gettime() is supported by the platform. */
#define HAVE_CLOCK_GETTIME 1

/* Define to 1 if you have the declaration of `optreset', and to 0 if you
   don't. */
#define HAVE_DECL_OPTRESET 0

/* Define to 1 if you have the declaration of `strerror_r', and to 0 if you
   don't. */
#define HAVE_DECL_STRERROR_R 1

/* Define to 1 if you have the <dlfcn.h> header file. */
#define HAVE_DLFCN_H 1

/* Define to 1 if you have the <ext/stdio_filebuf.h> header file. */
#define HAVE_EXT_STDIO_FILEBUF_H 1

/* Defined to 1 if ffs() is supported by the platform. */
#define HAVE_FFS 1

/* Define to 1 if you have the <getopt.h> header file. */
#define HAVE_GETOPT_H 1

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `gmp' library (-lgmp). */
#define HAVE_LIBGMP 1

/* Define to 1 if you have the `profiler' library (-lprofiler). */
/* #undef HAVE_LIBPROFILER */

/* Define to 1 to use libreadline */
#define HAVE_LIBREADLINE 0

/* Define to 1 if you have the `tcmalloc' library (-ltcmalloc). */
/* #undef HAVE_LIBTCMALLOC */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strerror_r' function. */
#define HAVE_STRERROR_R 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Defined to 1 if strtok_r() is supported by the platform. */
#define HAVE_STRTOK_R 1

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if you have the <unistd.h> header file. */
#define HAVE_UNISTD_H 1

/* Define to 1 if __gnu_cxx::is_sorted() exists */
#define IS_SORTED_IN_GNUCXX_NAMESPACE 1

/* Define to the sub-directory in which libtool stores uninstalled libraries.
   */
#define LT_OBJDIR ".libs/"

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT "cvc-bugs@cs.nyu.edu"

/* Define to the full name of this package. */
#define PACKAGE_NAME "cvc4"

/* Define to the full name and version of this package. */
#define PACKAGE_STRING "cvc4 1.4"

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME "cvc4"

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION "1.4"

/* Define to 1 if rl_completion_entry_function is declared to return pointer
   to char */
#define READLINE_COMPENTRY_FUNC_RETURNS_CHARP 0

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if strerror_r returns char *. */
#define STRERROR_R_CHAR_P 1

/* If the compiler supports a TLS storage class define it to that here */
#define TLS __thread

#endif /* __CVC4__CVC4AUTOCONFIG_H */
