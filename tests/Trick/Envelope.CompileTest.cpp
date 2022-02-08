#include "Trick/Envelope.h"
#include <concepts>

static_assert(std::regular<Trick::Envelope<std::vector<uint8_t>>>);
