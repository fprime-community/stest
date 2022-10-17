#!/bin/sh -e

# ---------------------------------------------------------------------- 
# clean.do
# ---------------------------------------------------------------------- 

. ./defs.sh

$SCRIPTS/clean_do
pan_files=`ls pan* | grep -v '\.do$' || true`
for file in $pan_files
do
  rm $file
done
doall rm 'test.txt' '*.trail'
