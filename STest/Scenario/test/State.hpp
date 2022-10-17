// ====================================================================== 
// \title  State.hpp
// \author bocchino
// \brief  State for STest scenario testing testing
//
// \copyright
// Copyright (C) 2017 California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// ====================================================================== 

#ifndef STest_State_HPP
#define STest_State_HPP

#include "STest/Rule/Rule.hpp"

#include "STest/types/basic_types.h"

namespace STest {

  struct State {

    State() :
      x(false)
    {

    }

    bool x;

  };

}

#endif
