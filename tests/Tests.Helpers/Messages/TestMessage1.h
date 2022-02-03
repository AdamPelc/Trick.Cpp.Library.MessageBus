#pragma once
#ifndef TRICK_MESSAGEBUS_TESTMESSAGE1_H
#define TRICK_MESSAGEBUS_TESTMESSAGE1_H

#include <string>

struct TestMessage1 {
  size_t id = 0;
  std::string string = "TestMessage1";
};

#endif// TRICK_MESSAGEBUS_TESTMESSAGE1_H
