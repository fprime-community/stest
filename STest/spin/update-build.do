#!/bin/sh -e

# ----------------------------------------------------------------------
# update-build.do
# ----------------------------------------------------------------------

. ./defs.sh

. $SCRIPTS/autocode
autocode_collect_files > autocode-files.txt
