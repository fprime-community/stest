// ====================================================================== 
// \title  testing.hpp
// \author bocchino
// \brief  Testing interface for spin
//
// \copyright
// Copyright (C) 2018 California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// ======================================================================

#ifndef STEST_SPIN_TESTING_HPP
#define STEST_SPIN_TESTING_HPP

#include "STest/spin/assert.hpp"

#define ASSERT_EQ(a, b) STEST_SPIN_ASSERT(a == b)
#define ASSERT_FALSE(a) STEST_SPIN_ASSERT(!a)
#define ASSERT_GE(a, b) STEST_SPIN_ASSERT(a >= b)
#define ASSERT_GT(a, b) STEST_SPIN_ASSERT(a > b)
#define ASSERT_LE(a, b) STEST_SPIN_ASSERT(a <= b)
#define ASSERT_LT(a, b) STEST_SPIN_ASSERT(a < b)
#define ASSERT_NE(a, b) STEST_SPIN_ASSERT(a != b)
#define ASSERT_TRUE(a) STEST_SPIN_ASSERT(a)

#endif
