#ifndef _ISCHEDULER_H_
#define _ISCHEDULER_H_

#include <functional>

namespace pipert {

template <class T>
class Channel;

template<class T>
class Packet;

class IScheduler {
 public:

  virtual ~IScheduler() {}

  template <class T>
  Channel<T> MakeChannel(const std::string& name,
    const std::function<void(Packet<T>)>& callback,
    int buffer_size)
  {
  }

  template <class T>
  Channel<T> MakeChannel(const void* mem_address, const std::string& name,
                         const std::function<void(Packet<T>)>& callback,
                         int buffer_size) {}

  virtual void Start() = 0;

  virtual void Stop() = 0;
};

}  // namespace pipert

#endif  //_ISCHEDULER_H_