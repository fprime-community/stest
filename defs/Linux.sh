#!/bin/sh

# ----------------------------------------------------------------------
# Linux.sh
# Build rules for Linux
# ----------------------------------------------------------------------

c_and_cpp_flags_Linux()
{
  var_require_set TARGET MODE STEST GTEST_INCLUDE_PATH
  echo "
-DSTEST_TARGET_"$TARGET"
-DSTEST_MODE_"$MODE"
-I$STEST
-I$GTEST_INCLUDE_PATH
-I$GTEST_INCLUDE_PATH/gtest/include
-Wall
-Wextra
-Wpedantic
-Werror
-Wno-unused-parameter
-Wno-keyword-macro
"
}

cpp_flags_Linux()
{
  c_and_cpp_flags_Linux
  echo "
--std=c++17
$LOCAL_CPP_FLAGS"
}

c_flags_Linux()
{
  c_and_cpp_flags_Linux
  echo "-std=c99
-std=gnu99
-fno-cond-mismatch
-Werror-implicit-function-declaration
-Wstrict-prototypes
$LOCAL_C_FLAGS"
}

makedepend_Linux() 
{
  dfile=$1
  src_file=$2
  evald "makedepend -f $dfile $LOCAL_MAKEDEPEND_FLAGS $src_file"
}

compile_cpp_Linux() 
{
  mode=$1
  dfile=$2
  src_file=$3
  ofile=$4
  flags=`cpp_flags_Linux`
  case $mode in
    *)
      evald "g++ -MD -MF $dfile -c $flags -o $ofile $src_file"
      ;;
  esac
}

compile_c_Linux() 
{
  mode=$1
  dfile=$2
  src_file=$3
  ofile=$4
  flags=`c_flags_Linux`
  case $mode in
    *)
      evald "gcc -MD -MF $dfile -c $flags -o $ofile $src_file"
      ;;
  esac
}

default_a_do_Linux()
{
  mode=$1
  afile=$2
  var_require_set GTEST_LIBRARY_PATH
  case $mode in
    *)
      evald "/usr/bin/ar rcs $afile $OFILES"
      evald "ranlib $afile"
      ;;
  esac
}

default_do_Linux()
{
  mode=$1
  exec_file=$2
  modules=$3
  flags="$LOCAL_LINKER_FLAGS -L$GTEST_LIBRARY_PATH -lgtest -ldl -lpthread -lm -lrt"
  case $mode in 
    *)
      evald "g++ -o $exec_file $modules $flags"
      ;;
  esac
}

strip_Linux()
{
  file=$1
  evald "strip $file"
}
