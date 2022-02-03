#include "Trick/Helpers/Concepts/IsContainer.h"
#include <vector>
#include <string>

// Positive Tests
static_assert(IsContainer<std::vector<uint8_t>>);
static_assert(IsContainer<std::string>);

// Negative Tests
static_assert(not IsContainer<int>);
