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
