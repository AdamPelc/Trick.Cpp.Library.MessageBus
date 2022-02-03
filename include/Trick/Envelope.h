#pragma once
#ifndef TRICK_MESSAGEBUS_ENVELOPE_H
#define TRICK_MESSAGEBUS_ENVELOPE_H

namespace Trick {
  template<class MessageType>
  class Envelope {
  public:
    explicit Envelope(MessageType message) : m_message(message) {}

  private:
    MessageType m_message;
  };
}

#endif// TRICK_MESSAGEBUS_ENVELOPE_H
