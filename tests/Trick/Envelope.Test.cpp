#include "Trick/Envelope.h"
#include "Tests.Helpers/Messages/TestMessage1.h"
#include "gtest/gtest.h"
#include <array>

TEST(EnvelopeTest, CreateAndReadSingleMessage) {
  // Aggregate
  TestMessage1 testMessage1;
  testMessage1.string = "TestMessage1";
  testMessage1.id = SIZE_MAX;

  // Act
  Trick::Envelope envelope(testMessage1);
  const auto actual_testMessage1 = envelope.ReadMessage();

  EXPECT_EQ(testMessage1.id, actual_testMessage1.id);
  EXPECT_EQ(testMessage1.string, actual_testMessage1.string);
}
