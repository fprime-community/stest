// ====================================================================== 
// \title  assert.cpp
// \author bocchino
// \brief  assert implementation
//
// \copyright
// Copyright (C) 2022 California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// ======================================================================

#include <assert.h>
#include <signal.h>
#include <stddef.h>
#include <stdio.h>

#include "STest/spin/assert.hpp"


namespace STest {

  namespace Spin {

    // ----------------------------------------------------------------------
    // Types 
    // ----------------------------------------------------------------------

    AssertFail ::
      AssertFail(
          const char *const file,
          const U32 line
      ) :
        file(file),
        line(line)
    {

    }

    void AssertFail ::
      abort()
    {
      char msg[MAX_MSG_SIZE];
      snprintf(
          msg,
          sizeof(msg),
          "STest assertion failed at %s: %u",
          this->file,
          this->line
      );
      if (uerror) {
        // uerror is initialized
        uerror(msg);
      }
      else {
        // uerror is not initialized
        fprintf(stderr, "%s\n", msg);
        fprintf(stderr, "STest::Spin::uerror is not initialized; aborting\n");
        static_cast<void>(raise(SIGABRT));
      }
    }

    // ----------------------------------------------------------------------
    // Extern global variables 
    // ----------------------------------------------------------------------

    void (*uerror)(char *msg) = NULL;

    // ----------------------------------------------------------------------
    // Global operators
    // ----------------------------------------------------------------------

    void operator<(
        AssertFail assertFail,
        ostream& os
    ) {
      assertFail.abort();
    }

  }

}
