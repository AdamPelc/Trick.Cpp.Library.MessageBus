#pragma once
#ifndef TRICK_MESSAGEBUS_CRATE_H
#define TRICK_MESSAGEBUS_CRATE_H

#include "Partition.h"
#include <memory>
#include <deque>
#include <any>
#include <unordered_map>
#include <utility>

namespace Trick {
  class Crate {
  public:
    template<typename TMessage>
    [[nodiscard]] bool Contains() const {
      const auto messageId = MessageId::Create<TMessage>();
      return mAllMessages.contains(messageId);
    }

    template<typename TMessage, Container TContainer = std::vector<TMessage>>
    [[nodiscard]] TContainer GetCopyOfMessages() const {
      const auto messageId = MessageId::Create<TMessage>();
      return mAllMessages.at(messageId)->template GetCopyOfMessages<TMessage>();
    }

    template<typename TMessage>
    void Insert(TMessage&& message) {
      if (Contains<TMessage>()) {
        Append(message);
      } else {
        CreateAndAdd(message);
      }
    }

    template<typename TMessage>
    void CreateAndAdd(TMessage&& message) {
      const auto messageId = MessageId::Create<TMessage>();

      mAllMessages.insert({
        messageId,
        std::make_shared<Partition>()
      });

      mAllMessages[messageId]->Add(std::forward<TMessage>(message));
    }

    template<typename TMessage>
    void Append(TMessage&& message) {
      const auto messageId = MessageId::Create<TMessage>();
      mAllMessages[messageId]->Add(std::forward<TMessage>(message));
    }
  private:
    std::unordered_map<MessageId, std::shared_ptr<Partition>> mAllMessages;
  };
}

#endif// TRICK_MESSAGEBUS_CRATE_H
