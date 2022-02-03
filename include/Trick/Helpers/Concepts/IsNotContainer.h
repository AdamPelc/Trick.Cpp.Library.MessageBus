#pragma once
#ifndef TRICK_MESSAGEBUS_ISNOTCONTAINER_H
#define TRICK_MESSAGEBUS_ISNOTCONTAINER_H

#include "IsContainer.h"
#include <concepts>
#include <iterator>

template<typename Type>
concept IsNotContainer = !IsContainer<Type>;

#endif// TRICK_MESSAGEBUS_ISNOTCONTAINER_H
