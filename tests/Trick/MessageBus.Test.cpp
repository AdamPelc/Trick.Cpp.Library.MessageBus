#define CATCH_CONFIG_MAIN
#include "Trick/MessageBus.h"
#include "catch2/catch.hpp"

SCENARIO("Can create new MessageBus", "[MessageBus]") {
  REQUIRE_NOTHROW(Trick::MessageBus());
}
