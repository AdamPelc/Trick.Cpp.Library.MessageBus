#pragma once
#ifndef TRICK_MESSAGEBUS_MESSAGEBUSUT_H
#define TRICK_MESSAGEBUS_MESSAGEBUSUT_H

#include <array>
#include <string>

struct TestMessage1 {
  size_t id = 0;
  std::string string = "TestMessage1.string - NotSet";
};

#endif// TRICK_MESSAGEBUS_MESSAGEBUSUT_H
