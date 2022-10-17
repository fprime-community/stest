class TrueConditionalScenario :
  public ConditionalScenario<State>
{
  public:
    TrueConditionalScenario(
        const char *const name,
        Scenario<State>& scenario
    ) :
      ConditionalScenario(name, scenario)
    {

    }
    bool condition_ConditionalScenario(const State& state) const { 
      return true; 
    }
    void nextRule_ConditionalScenario(const Rule<State> *const nextRule) {

    }
    void reset_ConditionalScenario() { 
    
    }
};
State state;
Set set;
RuleScenario<State> setScenario(set);
TrueConditionalScenario scenario(
    "TrueConditionalScenario",
    setScenario
);
ASSERT_FALSE(scenario.isDone());
const U32 numSteps = scenario.run(state);
ASSERT_EQ(1U, numSteps);
ASSERT_TRUE(scenario.isDone());
