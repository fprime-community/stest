#!/bin/sh -e

# ----------------------------------------------------------------------
# clean.do
# ----------------------------------------------------------------------

. ./defs.sh

subdir_targets redo clean
rm -rf build depend
rm_tmp
