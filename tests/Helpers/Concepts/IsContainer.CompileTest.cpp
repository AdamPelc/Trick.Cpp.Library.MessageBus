#include "Trick/Helpers/Concepts/Container.h"
#include <vector>
#include <string>
#include <array>

// Positive Tests
static_assert(Container<std::vector<uint8_t>>);
static_assert(Container<std::string>);
static_assert(Container<std::array<uint8_t, 2>>);

// Negative Tests
static_assert(not Container<int>);
