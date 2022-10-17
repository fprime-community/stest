#!/bin/sh -e

# ----------------------------------------------------------------------
# test.do
# ----------------------------------------------------------------------

exec >&2

. ./defs.sh

export MODE=default
if ! test -f selected.txt
then
  ./available | grep -v Error > selected.txt
fi
$SCRIPTS'/test/basic/select_tests'
