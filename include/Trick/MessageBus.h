#pragma once
#ifndef TRICK_MESSAGEBUS_MESSAGEBUS_H
#define TRICK_MESSAGEBUS_MESSAGEBUS_H

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

      //! \brief Reads all messages from MessageBus of MessageType.
      //! \tparam MessageType is used as message identifier.
      //! \return all messages of MessageType.
      template<typename MessageType, typename Container = std::vector<MessageType>>
      Container ReadAllMessages() {

        const auto& messages = messages_map[std::type_index(typeid(MessageType))];
        Container response(messages.size());

        auto messageIter = messages.begin();
        auto responseIter = response.begin();
        // Fill response container
        for (; messageIter != messages.end(); ++messageIter, ++responseIter) {
          *responseIter = std::any_cast<MessageType>(*messageIter);
        }
        return response;
      }

    private:
      std::unordered_map<std::type_index, std::deque<std::any>> messages_map;
    };
}

#endif// TRICK_MESSAGEBUS_MESSAGEBUS_H
