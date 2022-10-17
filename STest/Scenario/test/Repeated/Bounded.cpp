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
