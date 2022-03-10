#include "Trick/MessageBus.h"
#include "Test.Helpers/Messages/TestMessage1.h"
#include "catch2/catch.hpp"

SCENARIO("Receive Reference from MessageBus without existing Messages", "[Reference]") {
  GIVEN("A new MessageBus") {
    Trick::MessageBus messageBus;

    WHEN("reading Reference with not added Message") {
      const auto messagesReference = messageBus.GetReference<TestMessage1>();

      THEN("Reference should be null") {
        REQUIRE(messagesReference.IsNull());
      }
    }
  }
}
