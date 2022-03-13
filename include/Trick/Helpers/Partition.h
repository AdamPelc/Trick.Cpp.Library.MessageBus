#pragma once
#ifndef TRICK_MESSAGEBUS_PARTITION_H
#define TRICK_MESSAGEBUS_PARTITION_H

#include <any>
#include <deque>

namespace Trick {
  class Partition {
  public:
    template<typename TMessage>
    void Add(TMessage message) {
      mMessages.push_back(message);
    }

    template <typename TMessage, Container TContainer = std::vector<TMessage>>
    TContainer GetCopyOfMessages() {

      TContainer response(mMessages.size());
      auto responseIt = response.begin();
      auto messagesIt = mMessages.begin();
      for (; responseIt != response.end() ; ++responseIt, ++messagesIt ) {
        *responseIt = std::any_cast<TMessage>(*messagesIt);
      }

      return response;
    }

  private:
    std::deque<std::any> mMessages;
  };
}

#endif// TRICK_MESSAGEBUS_PARTITION_H
