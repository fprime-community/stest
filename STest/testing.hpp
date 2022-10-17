// ====================================================================== 
// \title  testing.hpp
// \author bocchino
// \brief  Symbols for testing
//
// \copyright
// Copyright (C) 2018-2022 California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// ======================================================================

#ifndef STEST_TESTING_HPP
#define STEST_TESTING_HPP

#if STEST_MODE_spin
#include "STest/spin/testing.hpp"
#else
#include <gtest/gtest.h>
#endif

#endif
