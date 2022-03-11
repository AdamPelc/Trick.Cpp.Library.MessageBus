#pragma once
#ifndef TRICK_MESSAGEBUS_MESSAGEBUS_H
#define TRICK_MESSAGEBUS_MESSAGEBUS_H

#include "Envelope.h"
#include "Helpers/MessageId.h"
  #include "Helpers/Crate.h"
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <any>
#include <deque>

namespace Trick {
    class MessageBus {
    public:
      //! \brief Puts message on MessageBus.
      //! \tparam MessageType is used as message identifier.
      //! \param message that will be put on MessageBus for further reference.
      template<typename MessageType>
      void Put(MessageType&& message) {
#ifdef _MSC_VER
        mCrate.Insert(message);
#else
        mCrate.template Insert(message);
#endif
      }

      //! \brief Receive Envelope with Message if exists.
      //! \details If Message does not exists returns empty envelope.
      template<typename TMessage, Container TContainer = std::vector<TMessage>>
      [[nodiscard]] TContainer GetMessagesCopy() const {

        if (mCrate.Contains<TMessage>()) {
          return mCrate.template GetCopyOfMessages<TMessage>();
        }

        return TContainer();
      }

    private:
      Crate mCrate;
    };
}

#endif// TRICK_MESSAGEBUS_MESSAGEBUS_H
