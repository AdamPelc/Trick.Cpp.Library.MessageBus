#pragma once
#ifndef TRICK_MESSAGEBUS_ENVELOPE_H
#define TRICK_MESSAGEBUS_ENVELOPE_H

#include "Helpers/Concepts/Container.h"
#include <utility>
#include <vector>
#include <concepts>

class MessageBus;

namespace Trick {
  template<typename MessageType>
  class Envelope {
  public:
    //! \brief Checks whether the Envelope is empty
    [[nodiscard]] constexpr bool Empty() const noexcept {
      return m_messages.empty();
    }

    //! \brief Gets message from Envelope
    [[nodiscard]] MessageType ReadMessage(const std::size_t index = 0) const {
      return m_messages.at(index);
    }

  private:
    std::vector<MessageType> m_messages;

    constexpr Envelope() = default;
    constexpr explicit Envelope(const Container auto& messages) : m_messages(messages) {}
    constexpr explicit Envelope(const MessageType& message) : m_messages{message} {}

    friend class MessageBus;
  };
}

#endif// TRICK_MESSAGEBUS_ENVELOPE_H
