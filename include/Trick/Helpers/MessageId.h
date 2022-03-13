#pragma once
#ifndef TRICK_MESSAGEBUS_MESSAGEID_H
#define TRICK_MESSAGEBUS_MESSAGEID_H

#include <typeindex>
#include <string>

namespace Trick {

  class MessageId {
  public:
    explicit MessageId(std::type_index typeIndex) : mTypeIndex(typeIndex) {}

    template<typename TMessage>
    [[nodiscard]] static MessageId Create() {
      return MessageId(std::type_index(typeid(TMessage)));
    }

    bool operator==(const MessageId &other) const {
      return mTypeIndex == other.mTypeIndex;
    }

  public:
    std::type_index mTypeIndex;
  };
}

namespace std {

  template <>
  struct hash<Trick::MessageId>
  {
    std::size_t operator()(const Trick::MessageId& key) const
    {
      using std::size_t;
      using std::hash;
      using std::string;
      
      return key.mTypeIndex.hash_code();
    }
  };

}

#endif// TRICK_MESSAGEBUS_MESSAGEID_H
