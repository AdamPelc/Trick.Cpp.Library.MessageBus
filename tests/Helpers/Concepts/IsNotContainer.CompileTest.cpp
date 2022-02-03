#include "Trick/Helpers/Concepts/IsNotContainer.h"
#include <vector>
#include <string>

// Positive Tests
static_assert(IsNotContainer<int>);

// Negative Tests
static_assert(not IsNotContainer<std::vector<uint8_t>>);
static_assert(not IsNotContainer<std::string>);
