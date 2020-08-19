#ifndef _POLLEDCHANNEL_H_
#define _POLLEDCHANNEL_H_

#include "pipert/Channel.h"

namespace pipert {

template <class T>
class PolledChannel : public Channel<T> {
 public:
  PolledChannel(char* name, int capacity);

  PacketToProcess<T> Poll();  ///< Returns empty object if there is no packet available
};

template <class T>
PolledChannel<T>::PolledChannel(char* name, int capacity)
  : Channel(name, capacity, nullptr, nullptr) {}

template <class T>
PolledChannel<T>::PacketToProcess<T> Poll() {
  Packet<T>* new_packet = reinterpret_cast<Packet<T>*>(GetNext());
  return PacketToProcess<T>(new_packet, this);
}

}  // namespace pipert

#endif  //_POLLEDCHANNEL_H_