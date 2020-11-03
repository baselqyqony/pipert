#ifndef _CHANNELIMPL_H_
#define _CHANNELIMPL_H_

#include <utility>

#include "pipert/PacketBase.h"
#include "pipert/Timer.h"
namespace pipert {

template <class T>
class MeasurementProfile : MeasurementProfileBase<class T> {
 public:
  const char* MesurementProfileName;
  const char* ChannelName;
  Timer::Time packetTimeStamp;
  Timer::Time AcquireTime;
  Timer::Time PushTime;
  Timer::Time PopTime;
  Timer::Time ExecutionStartTime;
  Timer::Time DroppingTime;
  int* threadID;

  //must 

  
	 public
  MeasurementProfile() : MeasurementProfileBase(false) {}
};
}  // namespace pipert
#endif