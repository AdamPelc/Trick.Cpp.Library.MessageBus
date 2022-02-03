#include "Trick/Envelope.h"
#include "Tests.Helpers/Messages/TestMessage1.h"
#include "gtest/gtest.h"

TEST(EnvelopeTest, Create) {
  // Agregate
  TestMessage1 testMessage1;
  EXPECT_NO_THROW(Trick::Envelope<TestMessage1> envelope(testMessage1));
}
