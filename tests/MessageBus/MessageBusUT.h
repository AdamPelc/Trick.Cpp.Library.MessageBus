#pragma once
#ifndef TRICK_MESSAGEBUS_MESSAGEBUSUT_H
#define TRICK_MESSAGEBUS_MESSAGEBUSUT_H

#include "gtest/gtest.h"
#include <array>

class MessageBusUT : public ::testing::Test {
public:
  struct TestMessage1 {
    size_t id = 0;
    std::string string = "TestMessage1";
  };

  struct TestMessage2 {
    size_t id = 0;
  };

};

#endif// TRICK_MESSAGEBUS_MESSAGEBUSUT_H
