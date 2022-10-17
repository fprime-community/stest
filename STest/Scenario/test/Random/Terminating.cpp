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
