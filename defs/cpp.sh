#!/bin/sh

# ----------------------------------------------------------------------
# cpp.sh
# Build rules for C and C++ files
# ----------------------------------------------------------------------

# Set the default target and mode
default_target_and_mode()
{
  var_use_default TARGET `uname`
  var_use_default MODE default
}

# Set target and mode
set_target_and_mode()
{
  if ! echo $1 | egrep -q '^build/[^/]+/[^/]' > /dev/null
  then
    error_no_rule $1
    return 1
  fi
  export TARGET=`echo $1 | cut -d '/' -f 2`
  export MODE=`echo $1 | cut -d '/' -f 3`
}

# Build a module library
build_module_lib()
{
  default_target_and_mode
  redo-ifchange build/$TARGET/$MODE/lib.a
}

# Build a module executable
build_module_exec()
{
  default_target_and_mode
  redo-ifchange build/$TARGET/$MODE/run
}

# Add .o files
ofiles()
{
  if ! test $# -gt 0
  then
    echoerr 'usage: ofiles path [file ...]'
    exit 1
  fi

  set_target_and_mode $1
  shift
  unset OFILES
  for file in $@
  do
    export OFILES="$OFILES "`echo $file | sed -e "s;^;build/$TARGET/$MODE/;" -e 's;\.[^.]*$;.o;'`
  done
}

# Add .a files
libs()
{
  if ! test $# -gt 0
  then
    echoerr 'usage: libs path [file ...]'
    exit 1
  fi

  set_target_and_mode $1
  shift
  unset LIBS
  for module in $@
  do
    export LIBS="$LIBS $STEST/$module/build/$TARGET/$MODE/lib.a"
  done
}

# Get the source file
get_source_file()
{
  path=`echo $1 | sed 's;^build/[^/]*/[^/]*/;;'`
  if test -f $path.cpp
  then
    echo $path.cpp
  elif test -f $path.cc
  then
    echo $path.cc
  elif test -f $path.c
  then
    echo $path.c
  else
    emit_error "no source file to build $1.o"
    exit 1
  fi
}

# Get the source language
get_source_language()
{
  if echo $1 | grep -q '\.cpp$'
  then
    echo cpp
  elif echo $1 | grep -q '\.cc$'
  then
    echo cpp
  elif echo $1 | grep -q '\.c$'
  then
    echo c
  else
    emit_error 'unknown source language for '$1
    exit 1
  fi

}

# Build a .o file from a .c file
default_o_do()
{
  set_target_and_mode $2

  dir=`dirname $2`
  source_file=`get_source_file $2`
  source_language=`get_source_language $source_file`
  dfile=`echo $2 | sed 's;^build;depend;'`.d

  mkdir -p $dir `dirname $dfile`
  redo-ifchange $source_file
  compile_$source_language'_'$TARGET $MODE $dfile $source_file $3
  redo_ifchange_d $dfile
}

# Redo if dependencies changed
redo_ifchange_d()
{
  for arg in "$@"; do
    deps=`tr '\n' ' ' < $arg`
    deps=`echo $deps | sed -e 's/^.*: *//' -e 's/\\\\//g'`
    echo $deps
  done | xargs redo-ifchange
}

# Build a .a file from several .o files
default_a_do()
{
  set_target_and_mode $2

  dir=`dirname $2`
  mkdir -p $dir

  if test -f 'autocode.do'
  then
    redo-ifchange autocode
  fi

  redo-ifchange $OFILES
  default_a_do_$TARGET $MODE $3
}

# Build an executable
default_do()
{
  set_target_and_mode $2

  dir=`dirname $2`
  mkdir -p $dir

  redo-ifchange $OFILES $LIBS
  default_do_$TARGET $MODE $3 "$OFILES $LIBS"
}
