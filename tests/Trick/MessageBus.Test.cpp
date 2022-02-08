#include "Trick/MessageBus.h"
#include "Tests.Helpers/Messages/TestMessage1.h"
#include "Tests.Helpers/Messages/TestMessage2.h"
#include "gtest/gtest.h"

TEST(MessageBusTest, Create) {
  ASSERT_NO_THROW(Trick::MessageBus());
}

TEST(MessageBusTest, ReadEmptyMessages) {
  // Aggregate
  Trick::MessageBus messageBus;

  // Act && Assert
  ASSERT_TRUE(messageBus.ReadAllMessages<TestMessage1>().empty());
}

TEST(MessageBusTest, PutAndReadMultipleMessages) {
  // Aggregate
  Trick::MessageBus messageBus;
  constexpr auto testMessage1Amount = 2U;
  std::array<TestMessage1, testMessage1Amount> testMessages1;
  testMessages1[1].id = 1;
  TestMessage2 testMessage2;

  // Act
  std::for_each(testMessages1.begin(), testMessages1.end(), [&messageBus](const auto& testMessage){
    EXPECT_NO_THROW(messageBus.Put(testMessage));
  });
  EXPECT_NO_THROW(messageBus.Put(testMessage2));

  const auto actualTestMessages1 = messageBus.ReadAllMessages<TestMessage1>();
  const auto actualTestMessages2 = messageBus.ReadAllMessages<TestMessage2>();

  // Assert
  ASSERT_EQ(testMessage1Amount, actualTestMessages1.size());
  EXPECT_EQ(testMessages1[0].id, actualTestMessages1[0].id);
  EXPECT_EQ(testMessages1[0].string, actualTestMessages1[0].string);
  EXPECT_EQ(testMessages1[1].id, actualTestMessages1[1].id);
  EXPECT_EQ(testMessages1[1].string, actualTestMessages1[1].string);

  ASSERT_EQ(1, actualTestMessages2.size());
  EXPECT_EQ(testMessage2.id, actualTestMessages2[0].id);
}
