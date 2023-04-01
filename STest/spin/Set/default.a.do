#!/bin/sh -e

# ----------------------------------------------------------------------
# default.a.do
# ----------------------------------------------------------------------

. ./defs.sh

export MODE=spin
export LOCAL_CPP_FLAGS="
-Wno-deprecated-declarations
-Wno-keyword-macro
-Wno-unused-but-set-parameter
"
redo-ifchange autocode
ofiles $2 pan.cpp
default_a_do "$@"
