#!/bin/sh

die () {
   echo "*** mkconfig.sh: $*" 1>&2
   exit 1
}

[ -f makefile ] || die "can not find 'makefile'"

cat<<EOF
/*************************************************************/
/* Automatically generated by './mkconfig.sh': do note edit! */
/*************************************************************/
EOF

echo "#define LGL_OS \"`uname -srmn`\""
echo "#define LGL_COMPILED \"`date`\""
cat<<EOF
#define LGL_RELEASED "Tue May 26 11:34:00 CEST 2015"
#define LGL_VERSION "azd"
#define LGL_ID "0d997521ad2e7d4e94f5d74a4665455b91309b62"
EOF