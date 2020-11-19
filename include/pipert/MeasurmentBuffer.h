#ifndef _CHANNELIMPL_H_
#define _CHANNELIMPL_H_

#include <utility>

#include "pipert/PacketBase.h"
#include "pipert/Timer.h"
namespace pipert {


class MeasurementBuffer {

private:
  // this function will start sending the buffer via UDP connection each
  // timeInterval and clear measuremensListList
  void SendingJobCallBack() { 
	  
	  while (enableSending) {

		    if (measuremensListList.size() == BufferSize) {
              connection.send(measuremensListList);
                      measuremensListList.clear();
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(timeInterval));

    }
  
  }

  
 
 std::thread SendingJob(SendingJobCallBack);


 public:
 uint16_t BufferSize;
 uint16_t TimeInterval;
 bool enableSending;
 UDPConnection connection;

 std::vector<MeasurementProfileBase> measuremensListList;


 //recieve function

 MeasurementBuffer(UDPConnection udpConnection, uint16_t timeIntervals,
                   uint16_t bufferSize;) {
   connection = udpConnection;
   BufferSize = bufferSize;
   TimeIntervals = timeIntervals;
   SendingJob.join();



 }



 void pushMeasurement(MeasurementProfileBase profile) 
 {
   if (measuremensListList.size() < BufferSize) {
     measuremensListList.add(profile);
   }
 
 }

 



}  // namespace pipert
#endif #pragma once
