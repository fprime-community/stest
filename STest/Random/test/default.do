#!/bin/sh -e

# ----------------------------------------------------------------------
# default.do
# ----------------------------------------------------------------------

. ./defs.sh

libs $2 "
STest/Random/test
STest
"
default_do "$@"
