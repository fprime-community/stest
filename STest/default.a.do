#!/bin/sh -e

# ----------------------------------------------------------------------
# default.a.do
# ----------------------------------------------------------------------

. ./defs.sh

redo-ifchange autocode
set_target_and_mode $2
case $MODE in
  spin)
    sources=spin
    ;;
  *)
    sources=default
    ;;
esac
ofiles $2 `cat sources/$sources.txt`
default_a_do "$@"
