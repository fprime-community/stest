#define PRECONDITION(RULE) c_expr { now.RULE.precondition(now.state) }
#define ACTION(RULE) c_code { printf("applying rule %s\n", now.RULE.name); now.RULE.apply(now.state); }

c_decl {
\#include "STest/spin/Rules.hpp"
\#include "STest/exported.hpp"
}

c_state "STest::State state" "Global"
c_state "STest::Set set" "Global"

active proctype test() {

  c_code { STest::Spin::uerror = uerror; }
  do
    :: PRECONDITION(set) -> ACTION(set)
    :: else -> break
  od;

}
