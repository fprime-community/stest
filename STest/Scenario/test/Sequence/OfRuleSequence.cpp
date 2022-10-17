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
