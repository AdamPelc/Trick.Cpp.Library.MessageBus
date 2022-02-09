#include "Trick/MessageBus.h"
#include "Test.Helpers/Messages/TestMessage1.h"
#include "catch2/catch.hpp"
#include <optional>

SCENARIO("Receive Envelope from MessageBus without Messages", "[Envelope]") {
  GIVEN("A new MessageBus") {
    Trick::MessageBus messageBus;

    WHEN("reading Envelope with not added Message") {
      const auto envelope = messageBus.GetEnvelope<TestMessage1>();

      THEN("Envelope should be empty") {
        REQUIRE(envelope.Empty());
      }
    }
  }
}

SCENARIO("Receive Envelope from MessageBus with single Messages", "[Envelope]") {
  GIVEN("A new MessageBus with added Messages") {
    Trick::MessageBus messageBus;
    TestMessage1 testMessage1{
      .id = SIZE_MAX,
      .string = "TestMessage1"
    };

    REQUIRE_NOTHROW(messageBus.Put(testMessage1));

    WHEN("reading Envelope with that Message") {
      const auto envelope = messageBus.GetEnvelope<TestMessage1>();

      THEN("Envelope can not be empty") {
        REQUIRE_FALSE(envelope.Empty());
      }

      THEN("Content of message is preserved") {
        REQUIRE(envelope.ReadMessage().id == testMessage1.id);
        REQUIRE(envelope.ReadMessage().string == testMessage1.string);
      }
    }
  }
}

SCENARIO("Receive Envelope from MessageBus with multiple Messages", "[Envelope]") {
  GIVEN("A new MessageBus with added Messages") {
    Trick::MessageBus messageBus;
    TestMessage1 testMessage1_0 {
      .id = 0,
      .string = "TestMessage1_0"
    };
    TestMessage1 testMessage1_1 {
      .id = 1,
      .string = "TestMessage1_1"
    };

    REQUIRE_NOTHROW(messageBus.Put(testMessage1_0));
    REQUIRE_NOTHROW(messageBus.Put(testMessage1_1));

    WHEN("reading Envelope with that Messages") {
      const auto envelope = messageBus.GetEnvelope<TestMessage1>();

      THEN("Envelope can not be empty") {
        REQUIRE_FALSE(envelope.Empty());
      }

      THEN("Content of message is preserved") {
        REQUIRE(envelope.ReadMessage(0).id == testMessage1_0.id);
        REQUIRE(envelope.ReadMessage(0).string == testMessage1_0.string);
        REQUIRE(envelope.ReadMessage(1).id == testMessage1_1.id);
        REQUIRE(envelope.ReadMessage(1).string == testMessage1_1.string);
      }
    }
  }
}
