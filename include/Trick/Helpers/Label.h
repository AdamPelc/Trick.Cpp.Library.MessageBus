#pragma once
#ifndef TRICK_MESSAGEBUS_LABEL_H
#define TRICK_MESSAGEBUS_LABEL_H

#include <typeindex>

namespace Trick {
  template<typename MessageType>
  class Label {
  public:
    [[nodiscard]] std::type_index Get() const {
      return std::type_index(typeid(MessageType));
    }
  };
}

#endif// TRICK_MESSAGEBUS_LABEL_H
