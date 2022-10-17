#!/bin/sh -e

# ----------------------------------------------------------------------
# git-clean.do
# Use `git clean` to remove untracked files
# WARNING: This will remove all files that are not checked in
# (unless they appear in .gitigore).
# ----------------------------------------------------------------------

. ./defs.sh

git clean -df 1>&2
find . -name '*redo*.tmp' | xargs rm -r
rm -rf .redo
