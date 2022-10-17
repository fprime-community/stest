#!/bin/sh

# ----------------------------------------------------------------------
# defs-root.sh
# Root definitions for redo build scripts
# ----------------------------------------------------------------------

# Trap control-C
trap 'exit 1' INT

canonicalize()
{
  (cd $1; pwd)
}

# Make echo print escape characters
if test -z "`echo -e`"
then
  alias echo='echo -e'
fi

# Environment variables
export STEST=`canonicalize $STEST`
export SCRIPTS=$STEST/scripts
export GREEN='\033[32m'
export NO_COLOR='\033[0m'
export RED='\033[31m'
export YELLOW='\033[33m'

# Standardize the sort order across platforms
export LC_ALL=C

# Global configuration
files=`ls $STEST/defs/*.sh`
for file in $files
do
  . $file
done
