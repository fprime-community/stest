// ====================================================================== 
// \title  assert.hpp
// \author bocchino
// \brief  assert interface
//
// \copyright
// Copyright (C) 2022 California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// ======================================================================

#ifndef STEST_SPIN_ASSERT_HPP
#define STEST_SPIN_ASSERT_HPP

// Operator < has higher precedence than a?b:c and lower precedence than <<.
// Therefore STEST_SPIN_ASSERT(e_1) << e_2 << ... << e_n expands to 
// (e_1) ? static_cast<void>(0) : (STest::Spin::AssertFail(__FILE__, __LINE__) < (STest::cerr << e_2 << ... << e_n)).
// By overloading the < operator to abort, we force evaluation of STest::cerr << e_2 << ... << e_n
// before aborting.
#define STEST_SPIN_ASSERT(expr) \
  (expr) ? static_cast<void>(0) : STest::Spin::AssertFail(__FILE__, __LINE__) < STest::cerr

#include "STest/iostream/ostream.hpp"
#include "STest/types/basic_types.h"

namespace STest {

  namespace Spin {

    // ----------------------------------------------------------------------
    // Constants
    // ----------------------------------------------------------------------

    enum Constants { 
      MAX_MSG_SIZE = 1024
    };

    // ----------------------------------------------------------------------
    // Types 
    // ----------------------------------------------------------------------

    //! Handle assertion failures
    struct AssertFail {

      //! Construct an AssertFail object
      AssertFail(
          const char *const file,
          const U32 line
      );

      //! Abort the execution
      void abort();

      //! The file name
      const char *const file;

      //! The line number
      const U32 line;

    };

    // ----------------------------------------------------------------------
    // Extern global variables 
    // ----------------------------------------------------------------------

    //! Spin error function (defined externally)
    extern void (*uerror)(char *msg);

    // ----------------------------------------------------------------------
    // Global operators
    // ----------------------------------------------------------------------

    void operator<(
        AssertFail assertFail,
        ostream& os
    );

  }

}

#endif
