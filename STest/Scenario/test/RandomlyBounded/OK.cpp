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
printf("numSteps=%u$n", numSteps);
