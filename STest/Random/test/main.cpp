// ====================================================================== 
// \title  main.cpp
// \author Rob Bocchino
// \brief  Main file for Random module tests
// ======================================================================

#include "STest/exported.hpp"

#define NUM_ITERATIONS 1000000

namespace STest {
 
 TEST(inUnitInterval, OK) {
   for (U32 i = 0; i < NUM_ITERATIONS; ++i) {
     const double d = Random::inUnitInterval();
     ASSERT_GE(d, 0.0);
     ASSERT_LE(d, 1.0);
   }
 }

 TEST(lowerUpper, OK) {
   for (U32 i = 0; i < NUM_ITERATIONS; ++i) {
     const U32 maxValue = 0xFFFFFFFFU;
     // Generate a random lower value
     const U32 lower = Random::lowerUpper(0, maxValue);
     ASSERT_LE(lower, maxValue);
     // Generate a random upper value
     const U32 upper = Random::lowerUpper(lower, maxValue);
     ASSERT_GE(upper, lower);
     ASSERT_LE(upper, maxValue);
     // Generate a random value bounded by lower and upper
     const U32 r = Random::lowerUpper(lower, upper);
     ASSERT_GE(r, lower);
     ASSERT_LE(r, upper);
   }
 }

 TEST(startLength, OK) {
   for (U32 i = 0; i < NUM_ITERATIONS; ++i) {
     const U32 maxValue = 0xFFFFFFFFU;
     // Generate a random start value
     const U32 start = Random::lowerUpper(0, maxValue);
     ASSERT_LE(start, maxValue);
     // Generate a random length
     const U32 length = Random::lowerUpper(1, maxValue - start + 1);
     ASSERT_GT(length, 1U);
     ASSERT_LE(length, maxValue - start + 1);
     // Generate a random value bounded by start and length
     const U32 r = Random::startLength(start, length);
     ASSERT_GE(r, start);
     ASSERT_LE(r, start + length - 1);
   }
 }

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  STest::Random::seed();
  return RUN_ALL_TESTS();
}
