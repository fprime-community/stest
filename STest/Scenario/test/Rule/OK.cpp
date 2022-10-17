State state;
Set set;
RuleScenario<State> ruleScenario(set);
ASSERT_FALSE(ruleScenario.isDone());
const U32 numSteps = ruleScenario.run(state);
ASSERT_EQ(1U, numSteps);
ASSERT_TRUE(ruleScenario.isDone());
