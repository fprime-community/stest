// ====================================================================== 
// \title  ostream.hpp
// \author bocchino
// \brief  ostream interface
//
// \copyright
// Copyright (C) 2022 California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// ======================================================================

#ifndef STEST_OSTREAM_HPP
#define STEST_OSTREAM_HPP

#include <stdio.h>

#include "STest/types/basic_types.h"

#if STEST_MODE_spin
#define STEST_COUT STest::cout
#define STEST_CERR STest::cerr
#else
#include <iostream>
#define STEST_COUT std::cout
#define STEST_CERR std::cerr
#endif

namespace STest {

  //! An ostream object for testing
  //! std::cout and std::cin are not compatible with Spin
  class ostream {

    public:

      //! Construct an ostream object
      ostream(
          FILE *const fp //!< The file pointer
      );

    public:

      //! Print a string value
      void print(
          const char *const val //!< The string value
      );

      //! Print an I32 value
      void print(
          const I32 val
      );

      //! Print a U32 value
      void print(
          const U32 val
      );

      //! Print a generic value
      template<typename T>void print(
          const T& val //!< The value
      ) {
        fprintf(fp, "[ object %p ]", &val);
      }

    private:

      //! The file pointer
      FILE *const fp;

  };

  extern ostream cout;

  extern ostream cerr;

  template<typename T>ostream& operator<<(
      ostream& os,
      const T& val
  ) {
    os.print(val);
    return os;
  }
}

#endif
