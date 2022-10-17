#!/bin/sh

# ----------------------------------------------------------------------
# Defs/error.sh
# Error messages
# ----------------------------------------------------------------------

# Echo args to stderr
echoerr()
{
  echo "$@" 1>&2
}

# Emit an error
emit_error()
{
  echoerr "${BOLD}${RED}${1}${NOCOLOR}"
}

# Error: No rule to build target
error_no_rule()
{
  emit_error 'No rule to build '$1
}

# Error: No command to build target
error_no_command()
{
  emit_error 'No command to build '$1
}
