#!/bin/sh -e

# ----------------------------------------------------------------------
# default.a.do
# ----------------------------------------------------------------------

. ./defs.sh

ofiles $2 main.cpp
redo-ifchange autocode
default_a_do "$@"