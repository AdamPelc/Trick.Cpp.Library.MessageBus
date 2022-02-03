#pragma once
#ifndef TRICK_MESSAGEBUS_ENVELOPE_H
#define TRICK_MESSAGEBUS_ENVELOPE_H

#include "Helpers/Concepts/IsNotContainer.h"
#include "Helpers/Concepts/IsContainer.h"

namespace Trick {
  template<class MessageType>
  class Envelope {
  public:
    explicit Envelope(MessageType message) : m_message(message) {}

    MessageType ReadMessage() const requires IsNotContainer<MessageType> {
      return {};
    }

    private:
    MessageType m_message;
  };
}

#endif// TRICK_MESSAGEBUS_ENVELOPE_H
