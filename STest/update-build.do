#!/bin/sh -e

# ----------------------------------------------------------------------
# update-build.do
# ----------------------------------------------------------------------

rm -rf sources
mkdir sources
ls spin/*.cpp Random/*.cpp iostream/*.cpp Random/*.c Pick/Pick.cpp Pick/Pick_spin.cpp > sources/spin.txt
ls iostream/*.cpp Random/*.cpp Random/*.c Pick/Pick.cpp Pick/Pick_default.cpp > sources/default.txt
