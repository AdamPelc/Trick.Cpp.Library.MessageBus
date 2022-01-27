#pragma once
#ifndef TRICK_MESSAGEBUS_MESSAGEBUSUT_H
#define TRICK_MESSAGEBUS_MESSAGEBUSUT_H

#include "gtest/gtest.h"
#include <array>

class MessageBusUT : public ::testing::Test {
public:
  struct TestMessage {
    uint64_t uint64 = 0;
    std::array<uint16_t, 2> arrayUint16{};
    std::string string;
  };

};

#endif// TRICK_MESSAGEBUS_MESSAGEBUSUT_H
