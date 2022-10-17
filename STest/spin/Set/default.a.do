#!/bin/sh -e

# ----------------------------------------------------------------------
# default.a.do
# ----------------------------------------------------------------------

. ./defs.sh

export MODE=spin
redo-ifchange autocode
ofiles $2 pan.cpp
default_a_do "$@"
