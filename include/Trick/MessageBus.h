#pragma once
#ifndef TRICK_MESSAGEBUS_MESSAGEBUS_H
#define TRICK_MESSAGEBUS_MESSAGEBUS_H

namespace Trick {
    class MessageBus {
    public:
      //! \brief Puts message on MessageBus.
      //! \tparam MessageType is used as message identifier.
      //! \param message that will be put on MessageBus for further reference.
      template<typename MessageType>
      void Put([[maybe_unused]]MessageType&& message) {

      }
    };
}

#endif// TRICK_MESSAGEBUS_MESSAGEBUS_H
