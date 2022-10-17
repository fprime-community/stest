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
