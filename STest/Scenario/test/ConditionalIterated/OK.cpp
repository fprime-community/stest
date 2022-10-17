class TrueConditionalIteratedScenario :
  public ConditionalIteratedScenario<State>
{
  public:
    TrueConditionalIteratedScenario(
        const char *const name,
        IteratedScenario<State>& scenario
    ) :
      ConditionalIteratedScenario(name, scenario)
    {

    }
    bool condition_ConditionalIteratedScenario(const State& state) const { 
      return true; 
    }
    void nextScenario_ConditionalIteratedScenario(
        const Scenario<State> *const nextScenario
    ) {

    }
};
State state;
Set set;
Rule<State>* rules[] = { &set };
RuleSequenceScenario<State> ruleSequenceScenario(
    "RuleSequenceScenario",
    rules,
    sizeof(rules) / sizeof(Rule<State>*)
);
TrueConditionalIteratedScenario scenario(
    "TrueConditionalIteratedScenario",
    ruleSequenceScenario
);
ASSERT_FALSE(scenario.isDone());
const U32 numSteps = scenario.run(state);
ASSERT_EQ(1U, numSteps);
ASSERT_TRUE(scenario.isDone());
