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
