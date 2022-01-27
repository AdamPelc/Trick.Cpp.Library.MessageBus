#include "Trick/MessageBus.h"
#include "MessageBusUT.h"

TEST_F(MessageBusUT, Create) {
  ASSERT_NO_THROW(Trick::MessageBus());
}

TEST_F(MessageBusUT, CreateAndPutMessage) {
  // Aggregate
  TestMessage testMessage;
  Trick::MessageBus messageBus;

  // Act && Assert
  ASSERT_NO_THROW(messageBus.Put(testMessage));
}
