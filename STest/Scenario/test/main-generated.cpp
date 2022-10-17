// ====================================================================== 
// \title  main.cpp
// \author AUTO-GENERATED: DO NOT EDIT
// \brief  Main file for Scenario module tests
//
// \copyright
// Copyright (C) 2022 California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
// ======================================================================

#include "local.hpp"
#include "STest/Random/Random.hpp"
#include "STest/Scenario/test/imported.hpp"

namespace STest {
 
 TEST(Apply, Error) {
   State state;
   Unset unset;
   unset.apply(state);
 }
 
 TEST(Conditional, OK) {
   class TrueConditionalScenario :
     public ConditionalScenario<State>
   {
     public:
       TrueConditionalScenario(
           const char *const name,
           Scenario<State>& scenario
       ) :
         ConditionalScenario(name, scenario)
       {
   
       }
       bool condition_ConditionalScenario(const State& state) const { 
         return true; 
       }
       void nextRule_ConditionalScenario(const Rule<State> *const nextRule) {
   
       }
       void reset_ConditionalScenario() { 
       
       }
   };
   State state;
   Set set;
   RuleScenario<State> setScenario(set);
   TrueConditionalScenario scenario(
       "TrueConditionalScenario",
       setScenario
   );
   ASSERT_FALSE(scenario.isDone());
   const U32 numSteps = scenario.run(state);
   ASSERT_EQ(1U, numSteps);
   ASSERT_TRUE(scenario.isDone());
 }
 
 TEST(Repeated, Bounded) {
   State state;
   Set set;
   Unset unset;
   Rule<State>* rules[] = { &set, &unset };
   RuleSequenceScenario<State> ruleSequenceScenario(
       "RuleSequenceScenario",
       rules,
       sizeof(rules) / sizeof(Rule<State>*)
   );
   RepeatedScenario<State> repeatedScenario(
       "RepeatedScenario",
       ruleSequenceScenario
   );
   BoundedScenario<State> boundedScenario(
       "BoundedScenario",
       repeatedScenario,
       100
   );
   const U32 numSteps = boundedScenario.run(state);
   ASSERT_EQ(100U, numSteps);
 }
 
 TEST(Rule, OK) {
   State state;
   Set set;
   RuleScenario<State> ruleScenario(set);
   ASSERT_FALSE(ruleScenario.isDone());
   const U32 numSteps = ruleScenario.run(state);
   ASSERT_EQ(1U, numSteps);
   ASSERT_TRUE(ruleScenario.isDone());
 }
 
 TEST(RandomlyBounded, OK) {
   State state;
   Set set;
   Unset unset;
   Rule<State>* rules[] = { &set, &unset };
   RuleSequenceScenario<State> ruleSequenceScenario(
       "RuleSequenceScenario",
       rules,
       sizeof(rules) / sizeof(Rule<State>*)
   );
   RepeatedScenario<State> repeatedScenario(
       "RepeatedScenario",
       ruleSequenceScenario
   );
   RandomlyBoundedScenario<State> randomlyBoundedScenario(
       "BoundedScenario",
       repeatedScenario,
       100,
       1000
   );
   const U32 numSteps = randomlyBoundedScenario.run(state);
   ASSERT_GE(numSteps, 100U);
   ASSERT_LT(numSteps, 1100U);
   printf("numSteps=%u\n", numSteps);
 }
 
 TEST(ConditionalIterated, OK) {
   class TrueConditionalIteratedScenario :
     public ConditionalIteratedScenario<State>
   {
     public:
       TrueConditionalIteratedScenario(
           const char *const name,
           IteratedScenario<State>& scenario
       ) :
         ConditionalIteratedScenario(name, scenario)
       {
   
       }
       bool condition_ConditionalIteratedScenario(const State& state) const { 
         return true; 
       }
       void nextScenario_ConditionalIteratedScenario(
           const Scenario<State> *const nextScenario
       ) {
   
       }
   };
   State state;
   Set set;
   Rule<State>* rules[] = { &set };
   RuleSequenceScenario<State> ruleSequenceScenario(
       "RuleSequenceScenario",
       rules,
       sizeof(rules) / sizeof(Rule<State>*)
   );
   TrueConditionalIteratedScenario scenario(
       "TrueConditionalIteratedScenario",
       ruleSequenceScenario
   );
   ASSERT_FALSE(scenario.isDone());
   const U32 numSteps = scenario.run(state);
   ASSERT_EQ(1U, numSteps);
   ASSERT_TRUE(scenario.isDone());
 }
 
 TEST(Selected, Terminating) {
   State state;
   Set set;
   Unset unset;
   Rule<State>* rules1[] = { &set, &unset, &set };
   RuleSequenceScenario<State> ruleSequenceScenario1(
       "RuleSequenceScenario1",
       rules1,
       sizeof(rules1) / sizeof(Rule<State>*)
   );
   Rule<State>* rules2[] = { &unset, &set, &unset };
   RuleSequenceScenario<State> ruleSequenceScenario2(
       "RuleSequenceScenario2",
       rules2,
       sizeof(rules2) / sizeof(Rule<State>*)
   );
   Scenario<State>* scenarios[] = {
     &ruleSequenceScenario1,
     &ruleSequenceScenario2
   };
   SelectedScenario<State> selectedScenario(
       "SelectedScenario",
       scenarios,
       sizeof(scenarios) / sizeof(Scenario<State>*)
   );
   const U32 numSteps = selectedScenario.run(state);
   ASSERT_EQ(3U, numSteps);
 }
 
 TEST(Selected, BoundedIterated) {
   State state;
   Set set;
   Unset unset;
   Rule<State>* rules1[] = { &set, &unset, &set };
   RuleSequenceScenario<State> ruleSequenceScenario1(
       "RuleSequenceScenario1",
       rules1,
       sizeof(rules1) / sizeof(Rule<State>*)
   );
   Rule<State>* rules2[] = { &unset, &set, &unset };
   RuleSequenceScenario<State> ruleSequenceScenario2(
       "RuleSequenceScenario2",
       rules2,
       sizeof(rules2) / sizeof(Rule<State>*)
   );
   Scenario<State>* scenarios[] = {
     &ruleSequenceScenario1,
     &ruleSequenceScenario2
   };
   SelectedScenario<State> selectedScenario(
       "SelectedScenario",
       scenarios,
       sizeof(scenarios) / sizeof(Scenario<State>*)
   );
   RepeatedScenario<State> repeatedScenario(
       "RepeatedScenario",
       selectedScenario
   );
   BoundedIteratedScenario<State> boundedIteratedScenario(
       "BoundedIteratedScenario",
       repeatedScenario,
       3
   );
   const U32 numSteps = boundedIteratedScenario.run(state);
   ASSERT_EQ(9U, numSteps);
 }
 
 TEST(Interleaved, Bounded) {
   State state;
   Set set;
   RepeatedRuleScenario<State> setScenario(set);
   Unset unset;
   RepeatedRuleScenario<State> unsetScenario(unset);
   Scenario<State>* scenarios[] = { &setScenario, &unsetScenario };
   InterleavedScenario<State> interleavedScenario(
       "InterleavedScenario",
       scenarios,
       sizeof(scenarios) / sizeof(Scenario<State>*)
   );
   BoundedScenario<State> boundedScenario(
       "BoundedScenario",
       interleavedScenario,
       100
   );
   const U32 numSteps = boundedScenario.run(state);
   ASSERT_EQ(100U, numSteps);
 }
 
 TEST(Interleaved, Terminating) {
   State state;
   Set set;
   Unset unset;
   RuleScenario<State> setScenario(set);
   RuleScenario<State> unsetScenario(unset);
   Scenario<State>* scenarios[] = { &setScenario, &unsetScenario };
   InterleavedScenario<State> interleavedScenario(
       "InterleavedScenario",
       scenarios,
       sizeof(scenarios) / sizeof(Scenario<State>*)
   );
   const U32 numSteps = interleavedScenario.run(state);
   ASSERT_EQ(2U, numSteps);
 }
 
 TEST(Bounded, OK) {
   State state;
   NoOp noOp;
   RepeatedRuleScenario<State> noOpScenario(noOp);
   BoundedScenario<State> scenario(
       "BoundedScenario",
       noOpScenario,
       10
   );
   const U32 numSteps = scenario.run(state);
   ASSERT_EQ(10U, numSteps);
 }
 
 TEST(RepeatedRule, OK) {
   State state;
   Set set;
   RepeatedRuleScenario<State> scenario(set);
   ASSERT_FALSE(scenario.isDone());
   Rule<State>* rule = NULL;
   for (U32 i = 0; i < 10; ++i) {
     rule = scenario.nextRule(state);
     ASSERT_TRUE(rule != NULL);
   }
   ASSERT_TRUE(rule != NULL);
   rule->apply(state);
   ASSERT_FALSE(scenario.isDone());
 }
 
 TEST(RuleSequence, OK) {
   State state;
   Set set;
   Unset unset;
   Rule<State>* rules[] = { &set, &unset };
   RuleSequenceScenario<State> scenario(
       "RuleSequenceScenario",
       rules,
       sizeof(rules) / sizeof(Rule<State>*)
   );
   const U32 numSteps = scenario.run(state);
   ASSERT_EQ(2U, numSteps);
 }
 
 TEST(Random, Bounded) {
   State state;
   Set set;
   Unset unset;
   Rule<State>* rules[] = { &set, &unset };
   RandomScenario<State> randomScenario(
       "RandomScenario",
       rules,
       sizeof(rules) / sizeof(Rule<State>*)
   );
   BoundedScenario<State> boundedScenario(
       "BoundedScenario",
       randomScenario,
       100
   );
   const U32 numSteps = boundedScenario.run(state);
   ASSERT_EQ(100U, numSteps);
 }
 
 TEST(Random, Terminating) {
   State state;
   Set set;
   Rule<State>* rules[] = { &set };
   RandomScenario<State> randomScenario(
       "RandomScenario",
       rules,
       sizeof(rules) / sizeof(Rule<State>*)
   );
   const U32 numSteps = randomScenario.run(state);
   ASSERT_EQ(1U, numSteps);
 }
 
 TEST(Random, Interleaved) {
   State state;
   Set set;
   Unset unset;
   Rule<State>* rules[] = { &set, &unset };
   RandomScenario<State> randomScenario1(
       "RandomScenario1", 
       rules,
       sizeof(rules) / sizeof(Rule<State>*)
   );
   RandomScenario<State> randomScenario2(
       "RandomScenario2", 
       rules,
       sizeof(rules) / sizeof(Rule<State>*)
   );
   Scenario<State>* scenarios[] = { 
     &randomScenario1,
     &randomScenario2 
   };
   InterleavedScenario<State> interleavedScenario(
       "InterleavedScenario",
       scenarios,
       sizeof(scenarios) / sizeof(Scenario<State>*)
   );
   BoundedScenario<State> boundedScenario(
       "BoundedScenario",
       interleavedScenario,
       100
   );
   const U32 numSteps = boundedScenario.run(state);
   ASSERT_EQ(100U, numSteps);
 }
 
 TEST(Sequence, OfNoOp) {
   State state;
   NoOp noOp;
   RuleScenario<State> noOpScenario(noOp);
   Scenario<State>* scenarios[] = { 
     &noOpScenario,
     &noOpScenario,
     &noOpScenario
   };
   SequenceScenario<State> sequenceScenario(
       "SequenceScenario",
       scenarios,
       sizeof(scenarios) / sizeof(Scenario<State>*)
   );
   const U32 numSteps = sequenceScenario.run(state);
   ASSERT_EQ(3U, numSteps);
 }
 
 TEST(Sequence, OfRuleSequence) {
   State state;
   Set set;
   Unset unset;
   Rule<State>* rules1[] = { &set, &unset, &set };
   RuleSequenceScenario<State> ruleSequenceScenario1(
       "SequenceScenario1",
       rules1,
       sizeof(rules1) / sizeof(Rule<State>*)
   );
   Rule<State>* rules2[] = { &unset, &set, &unset };
   RuleSequenceScenario<State> ruleSequenceScenario2(
       "SequenceScenario2",
       rules2,
       sizeof(rules2) / sizeof(Rule<State>*)
   );
   Scenario<State>* scenarios[] = { 
     &ruleSequenceScenario1,
     &ruleSequenceScenario2,
     &ruleSequenceScenario1
   };
   SequenceScenario<State> sequenceScenario(
       "SequenceScenario",
       scenarios,
       sizeof(scenarios) / sizeof(Scenario<State>*)
   );
   const U32 numSteps = sequenceScenario.run(state);
   ASSERT_EQ(9U, numSteps);
 }
 
 TEST(BoundedIterated, OK) {
   State state;
   Set set;
   Unset unset;
   Rule<State>* rules[] = { &set, &unset };
   RuleSequenceScenario<State> ruleSequenceScenario(
       "RuleSequenceScenario",
       rules,
       sizeof(rules) / sizeof(Rule<State>*)
   );
   RepeatedScenario<State> repeatedScenario(
       "RepeatedScenario",
       ruleSequenceScenario
   );
   BoundedIteratedScenario<State> boundedIteratedScenario(
       "BoundedIteratedScenario",
       repeatedScenario,
       3
   );
   const U32 numSteps = boundedIteratedScenario.run(state);
   ASSERT_EQ(6U, numSteps);
 }

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  STest::Random::seed();
  return RUN_ALL_TESTS();
}
