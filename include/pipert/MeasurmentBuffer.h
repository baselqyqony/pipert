#ifndef _CHANNELIMPL_H_
#define _CHANNELIMPL_H_

#include <utility>

#include "pipert/PacketBase.h"
#include "pipert/Timer.h"
namespace pipert {

template <class T>
class MeasurementBuffer {

public:

  void pushMeasurement(MeasurementProfileBase profile);
   

private:
  PushBufferToUDPConnection();
 UDPConnection connection;
 int BufferSize;

}  // namespace pipert
#endif #pragma once
