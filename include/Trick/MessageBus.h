#pragma once
#ifndef TRICK_MESSAGEBUS_MESSAGEBUS_H
#define TRICK_MESSAGEBUS_MESSAGEBUS_H

#include "Envelope.h"
#include "Reference.h"
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
        messages_map[std::type_index(typeid(MessageType))].emplace_back(std::forward<MessageType>(message));
      }

      //! \brief Receive Envelope with Message if exists.
      //! \details If Message does not exists returns empty envelope.
      template<typename MessageType>
      [[nodiscard]] Envelope<MessageType> GetEnvelope() const {

        if (ContainsSingleMessage<MessageType>()) {
          return EnvelopeWithSingleMessage<MessageType>();
        }

        if (ContainsMultipleMessages<MessageType>()) {
          return EnvelopeWithMultipleMessages<MessageType>();
        }

        return Envelope<MessageType>();
      }

      template<typename MessageType>
      [[nodiscard]] Reference<MessageType> GetReference() const {
        return Reference<MessageType>();
      }

      private:
      std::unordered_map<std::type_index, std::deque<std::any>> messages_map;

      template<typename MessageType>
      [[nodiscard]] bool Contains() const noexcept {
        return messages_map.contains(std::type_index(typeid(MessageType)));
      }

      template<typename MessageType>
      [[nodiscard]] std::type_index GetMessageKey() const noexcept {
        return std::type_index(typeid(MessageType));
      }

      template<typename MessageType>
      [[nodiscard]] bool ContainsSingleMessage() const noexcept {
        if(Contains<MessageType>()) {
          return 1 == messages_map.at(GetMessageKey<MessageType>()).size();
        }
        return false;
      }

      template<typename MessageType>
      [[nodiscard]] bool ContainsMultipleMessages() const noexcept {
        if(Contains<MessageType>()) {
          return 1 < messages_map.at(GetMessageKey<MessageType>()).size();
        }
        return false;
      }

      template<typename MessageType>
      [[nodiscard]] Envelope<MessageType> EnvelopeWithSingleMessage() const {
        auto messages = messages_map.at(std::type_index(typeid(MessageType)));
        return Envelope<MessageType>(std::any_cast<MessageType>(messages.front()));
      }

      template<typename MessageType>
      [[nodiscard]] Envelope<MessageType> EnvelopeWithMultipleMessages() const {
        auto messagesEncoded = messages_map.at(std::type_index(typeid(MessageType)));
        std::vector<MessageType> messagesDecoded(messagesEncoded.size());

        auto messageEncodedIter = messagesEncoded.begin();
        auto messageDecodedIter = messagesDecoded.begin();

        // Fill response container
        for (; messageEncodedIter != messagesEncoded.end(); ++messageEncodedIter, ++messageDecodedIter) {
          *messageDecodedIter = std::any_cast<MessageType>(*messageEncodedIter);
        }
        return Envelope<MessageType>(messagesDecoded);
      }
    };
}

#endif// TRICK_MESSAGEBUS_MESSAGEBUS_H
