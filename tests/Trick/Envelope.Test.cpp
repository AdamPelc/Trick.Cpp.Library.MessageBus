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

TEST(EnvelopeTest, CreateAndReadContainerOfMessages) {
  // Aggregate
  std::array<TestMessage1, 2> testMessages1;
  testMessages1[0].string = "TestMessage1_0";
  testMessages1[0].id = SIZE_MAX;
  testMessages1[1].string = "TestMessage1_1";
  testMessages1[1].id = SIZE_MAX - 1;

  // Act
  Trick::Envelope envelope(testMessages1);
  const auto actual_testMessages1 = envelope.ReadAllMessages();

  EXPECT_EQ(testMessages1[0].id, actual_testMessages1[0].id);
  EXPECT_EQ(testMessages1[0].string, actual_testMessages1[0].string);
  EXPECT_EQ(testMessages1[1].id, actual_testMessages1[1].id);
  EXPECT_EQ(testMessages1[1].string, actual_testMessages1[1].string);
}

TEST(EnvelopeTest, CreateAndReadContainerOfEmptyMessages) {
  // Aggregate
  std::vector<TestMessage1> testMessages1;

  // Act
  Trick::Envelope envelope(testMessages1);
  const auto actual_testMessages1 = envelope.ReadMessages();

  try {
    EXPECT_EQ(testMessages1[0].id, actual_testMessages1[0].id);
  } catch ( std::exception& exception ) {
    std::cout << "exception.what()" << exception.what() << "\n";
  }

//  EXPECT_EQ(testMessages1[0].string, actual_testMessages1[0].string);
//  EXPECT_EQ(testMessages1[1].id, actual_testMessages1[1].id);
//  EXPECT_EQ(testMessages1[1].string, actual_testMessages1[1].string);
}
