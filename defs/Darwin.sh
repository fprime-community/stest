#!/bin/sh

# ----------------------------------------------------------------------
# Darwin.sh
# Build rules for Darwin
# ----------------------------------------------------------------------

cpp_flags_Darwin()
{
  var_require_set TARGET MODE STEST GTEST_INCLUDE_PATH
  echo "
-DSTEST_TARGET_"$TARGET"
-DSTEST_MODE_"$MODE"
--std=c++11
-I$STEST
-I$GTEST_INCLUDE_PATH
-I$GTEST_INCLUDE_PATH/gtest/include
-g3
-Os
-Wall
-Werror
-Wextra
-Wpedantic
-Wno-unused-parameter
$LOCAL_CPP_FLAGS
"
}

c_flags_Darwin()
{
  cpp_flags_Darwin
  echo "
-std=c99
-std=gnu99
-Werror-implicit-function-declaration
-Wstrict-prototypes
$LOCAL_C_FLAGS
"
}

makedepend_Darwin()
{
  dfile=$1
  src_file=$2
  evald "makedepend -f $dfile $LOCAL_MAKEDEPEND_FLAGS $src_file"
}

compile_cpp_Darwin()
{
  mode=$1
  dfile=$2
  src_file=$3
  ofile=$4
  flags=`cpp_flags_Darwin`
  evald "clang++ -MD -MF $dfile -c $flags -o $ofile $src_file"
}

compile_c_Darwin()
{
  mode=$1
  dfile=$2
  src_file=$3
  ofile=$4
  flags=`c_flags_Darwin`
  evald "clang -MD -MF $dfile -c $flags -o $ofile $src_file"
}

default_a_do_Darwin()
{
  mode=$1
  afile=$2
  evald "ar rcs $afile $OFILES"
}

default_do_Darwin()
{
  mode=$1
  exec_file=$2
  modules=$3
  var_require_set GTEST_LIBRARY_PATH
  clang_flags="-L$GTEST_LIBRARY_PATH -lgtest -ldl -lpthread -lm -lc++"
  evald "clang -o $exec_file $modules $LOCAL_LINKER_FLAGS $clang_flags"
}

strip_Darwin()
{
  file=$1
  evald "strip $file"
}
