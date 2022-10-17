#!/bin/sh

# ----------------------------------------------------------------------
# Defs/general.sh
# General definitions for redo build scripts
# ----------------------------------------------------------------------

# Echo green text
echo_green()
{
  echo "${BOLD}${GREEN}$@${NO_COLOR}"
}

# Echo red text
echo_red()
{
  echo "${BOLD}${RED}$@${NO_COLOR}"
}

# Echo yellow text
echo_yellow()
{
  echo "${BOLD}${YELLOW}$@${NO_COLOR}"
}

# Echo $@ to stderr; eval $@
evalp()
{
  echoerr "$@"
  $@
}

# Eval $@; echo $@ to stderr if in debug mode
evald()
{
  if test -n "$DEBUG"
  then
    echoerr $@
  fi
  eval $@
}

# Do command on all files matching regex
doall()
{
  if test "$#" -lt 1
  then
    echoerr 'usage: doall command pattern ...'
    return 1
  fi

  cmd=$1
  shift
  for regex in "$@"
  do
    shift
    for file in `find . -maxdepth 1 -name "$regex"`
    do
      evald "$cmd $file"
    done
  done
}

# Remove temporary files
rm_tmp() 
{
  doall 'rm -r' '*~' '*redo*tmp' '*.bak'
}

# Find subdirectories
subdirs()
{
  for file in `ls`
  do
    if test -d $file
    then
      echo $file
    fi
  done
}

# Run target in parallel all immediate subdirectories
subdir_targets()
{
  for path in `find . -maxdepth 2 -mindepth 2 -name $2.do`
  do
    dir=`dirname $path`
    echo $dir/$2
  done | xargs $1
}

# Run target sequentially in all immediate subdirectories
subdir_targets_sequential()
{
  for path in `find . -maxdepth 2 -mindepth 2 -name $2.do`
  do
    dir=`dirname $path`
    $1 $dir/$2
  done
}


# Run target in all recursive subdirectories
recursive_subdir_targets()
{
  for path in `find . -mindepth 2 -name $2.do`
  do
    dir=`dirname $path`
    echo $dir/$2
  done | xargs $1
}

# Check whether $1 contains $2
contains()
{
  echo $1 | grep -q $2 1>&2 2>/dev/null
}

