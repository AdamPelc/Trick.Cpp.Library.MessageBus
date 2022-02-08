#define CATCH_CONFIG_MAIN
#include "Trick/MessageBus.h"
#include "MessageBus.Test.h"
#include "catch2/catch.hpp"

SCENARIO("New MessageBus doesn't create exception", "[MessageBus]") {
  REQUIRE_NOTHROW(Trick::MessageBus());
}

SCENARIO("Default MessageBus returns no messages", "[MessageBus]") {
  GIVEN("A new MessageBus") {
    Trick::MessageBus messageBus;

    REQUIRE(messageBus.ReadAllMessages<TestMessage1>().empty());
  }
}

SCENARIO("Content of message added to and read from MessageBus should match", "[MessageBus]") {
  GIVEN("A new MessageBus") {
    Trick::MessageBus messageBus;

    WHEN("adding new message") {
      TestMessage1 testMessage1{
      .id = SIZE_MAX,
      .string = "TestMessage1"
      };

      REQUIRE_NOTHROW(messageBus.Put(testMessage1));

      THEN("same message should be received") {
        const auto actualTestMessage1 = messageBus.ReadAllMessages<TestMessage1>();

        REQUIRE(actualTestMessage1.front().id == testMessage1.id);
        REQUIRE(actualTestMessage1.front().string == testMessage1.string);
      }
    }
  }
}
