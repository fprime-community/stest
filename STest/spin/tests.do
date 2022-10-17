#!/bin/sh -e

# ----------------------------------------------------------------------
# tests_do
# Run tests
# ----------------------------------------------------------------------

. ./defs.sh

if test -z "`which spin`"
then
  echo "[ skipping spin tests: spin is not available ]" 1>&2
  exit 0
fi

$SCRIPTS'/test/tests_do'
