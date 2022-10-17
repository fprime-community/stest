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
