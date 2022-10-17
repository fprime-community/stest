State state;
NoOp noOp;
RuleScenario<State> noOpScenario(noOp);
Scenario<State>* scenarios[] = { 
  &noOpScenario,
  &noOpScenario,
  &noOpScenario
};
SequenceScenario<State> sequenceScenario(
    "SequenceScenario",
    scenarios,
    sizeof(scenarios) / sizeof(Scenario<State>*)
);
const U32 numSteps = sequenceScenario.run(state);
ASSERT_EQ(3U, numSteps);
