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
