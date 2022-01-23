#include "Trick/MessageBus.h"
#include "gtest/gtest.h"

TEST(MessageBus, Create) {
  ASSERT_NO_THROW(Trick::MessageBus());
}
