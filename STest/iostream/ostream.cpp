// ====================================================================== 
// \title  ostream.cpp
// \author bocchino
// \brief  ostream implementation
//
// \copyright
// Copyright (C) 2022 California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// ======================================================================

#include "STest/iostream/ostream.hpp"

namespace STest {

  ostream ::
    ostream(FILE *const fp) :
      fp(fp)
  {

  }

  void ostream ::
    print(const char *const val)
  {
    (void) fprintf(fp, "%s", val);
  }

  void ostream ::
    print(const I32 val)
  {
    (void) fprintf(fp, "%d", val);
  }

  void ostream ::
    print(const U32 val)
  {
    (void) fprintf(fp, "%u", val);
  }

  ostream cout(stdout);

  ostream cerr(stderr);

}
