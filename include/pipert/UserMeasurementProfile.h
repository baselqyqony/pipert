#ifndef _CHANNELIMPL_H_
#define _CHANNELIMPL_H_

#include <utility>

#include "pipert/PacketBase.h"
#include "pipert/Timer.h"
namespace pipert {

template <class T>
class UserMeasurementProfile : MesurementProfileBase {
  using Callback = std::function<void(PacketToProcess<T>,std::map<std::string ,double> & result)>;
 public:
  const char* MesurementProfileName;
  const char* ChannelName;
  Timer::Time packetTimeStamp;
  Timer::Time AcquireTime;
  Timer::Time PushTime;
  Timer::Time PopTime;
  Timer::Time ExecutionStartTime;
  Timer::Time DroppingTime;
  std::map<std::string ,double> userCallBackFunctionResult;
  Callback MeasurementProcessingFunction;

  MesurementProfileBase(Callback measurementProcessingFunction)
      : MeasurementProfileBase(true) {
    MeasurementProcessingFunction = measurementProcessingFunction;

  }

	 
};
}  // namespace pipert
#endif