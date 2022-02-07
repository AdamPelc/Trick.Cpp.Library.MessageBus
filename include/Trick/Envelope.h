#pragma once
#ifndef TRICK_MESSAGEBUS_ENVELOPE_H
#define TRICK_MESSAGEBUS_ENVELOPE_H

#include "Helpers/Concepts/Container.h"
#include <vector>

namespace Trick {
  template<typename MessageType>
  class Envelope {
  public:
    explicit Envelope(MessageType message) : m_message(message) {}

    MessageType ReadMessage() const {
      return m_message;
    }

    private:
    MessageType m_message;
  };

  template<Container MessagesContainer>
  class Envelope<MessagesContainer> {
  public:
    explicit Envelope(const MessagesContainer& messagesContainer)
      : m_messages(messagesContainer.begin(), messagesContainer.end()) {}

    auto ReadMessages() const {
      return m_messages;
    }

  private:
    std::vector<typename MessagesContainer::value_type> m_messages;
  };
}

#endif// TRICK_MESSAGEBUS_ENVELOPE_H
