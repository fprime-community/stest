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
