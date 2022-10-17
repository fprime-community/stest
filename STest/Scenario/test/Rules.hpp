// ====================================================================== 
// \title  Rules.hpp
// \author bocchino
// \brief  Rules for STest scenario testing
//
// \copyright
// Copyright (C) 2017 California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// ====================================================================== 

#ifndef STest_Rules_HPP
#define STest_Rules_HPP

#include "STest/Rule/Rule.hpp"

#include "STest/Scenario/test/State.hpp"

namespace STest {

  class NoOp : 
    public Rule<State> 
  {

    public:

      NoOp() :
        Rule<State>("NoOp")
      {

      }

      bool precondition(const State& state) {
        return true;
      }

    protected:

      void action(State& state) {

      }

  };

  class Set : 
    public Rule<State> 
  {

    public:

      Set() :
        Rule<State>("Set")
      {

      }

      bool precondition(const State& state) {
        return state.x == false;
      }

    protected:

      void action(State& state) {
        state.x = true;
      }

  };

  class Unset : 
    public Rule<State> 
  {

    public:

      Unset() :
        Rule<State>("Unset")
      {

      }

      bool precondition(const State& state) {
        return state.x == true;
      }

    protected:

      void action(State& state) {
        state.x = false;
      }

  };

}

#endif
