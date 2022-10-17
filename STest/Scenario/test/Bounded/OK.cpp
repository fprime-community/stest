State state;
NoOp noOp;
RepeatedRuleScenario<State> noOpScenario(noOp);
BoundedScenario<State> scenario(
    "BoundedScenario",
    noOpScenario,
    10
);
const U32 numSteps = scenario.run(state);
ASSERT_EQ(10U, numSteps);
