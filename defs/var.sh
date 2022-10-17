#!/bin/sh

# ----------------------------------------------------------------------
# Defs/var.sh
# Shell variables
# ----------------------------------------------------------------------

# Print the value of a variable
var_print()
{
  for var in $@
  do
    echo $var=`var_get_value $var`
  done
}

# Get the value of variable $1
var_get_value()
{
  eval 'echo $'$1
}

# Set variable $1 to $2 value if not set
var_use_default()
{
  if test -z "`var_get_value $1`"
  then
    eval 'export '$1'='$2
  fi
}

# Test whether variable $1 is set
var_test_set()
{
  test -n "`var_get_value $1`"
}

# Require that variables $@ be set
var_require_set()
{
  for var in $@
  do
    if ! var_test_set $var
    then
      emit_error $var' is not set'
      exit 1
    fi
  done
}
