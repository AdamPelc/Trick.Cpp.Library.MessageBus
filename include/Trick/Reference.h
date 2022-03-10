#pragma once
#ifndef TRICK_MESSAGEBUS_REFERENCE_H
#define TRICK_MESSAGEBUS_REFERENCE_H

namespace Trick {
  template<typename MessageType>
  class Reference {
  public:
    [[nodiscard]] constexpr bool IsNull() const noexcept {
      return true;
    }
  };
}

#endif// TRICK_MESSAGEBUS_REFERENCE_H
