State state;
Set set;
RepeatedRuleScenario<State> scenario(set);
ASSERT_FALSE(scenario.isDone());
Rule<State>* rule = NULL;
for (U32 i = 0; i < 10; ++i) {
  rule = scenario.nextRule(state);
  ASSERT_TRUE(rule != NULL);
}
ASSERT_TRUE(rule != NULL);
rule->apply(state);
ASSERT_FALSE(scenario.isDone());
