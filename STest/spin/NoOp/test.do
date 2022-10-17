#!/bin/sh -e

# ----------------------------------------------------------------------
# test.do
# ----------------------------------------------------------------------

. ./defs.sh

exec 1>&2

export TARGET=`uname`
export MODE=spin

redo-ifchange build/$TARGET/$MODE/run
if build/$TARGET/$MODE/run > 'test.txt'
then
  status=0
else
  status=1
fi

assert_fail=`grep 'assertion failed' < 'test.txt' || true`

if ! test $status -eq 0
then
  echo_red FAILED
elif test -n "$assert_fail"
then
  echo $assert_fail
  echo_red FAILED
else
  echo_green PASSED
fi

exit $status
