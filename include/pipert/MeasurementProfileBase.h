#ifndef _CHANNELIMPL_H_
#define _CHANNELIMPL_H_

#include <utility>

#include "pipert/PacketBase.h"
#include "pipert/Timer.h"
namespace pipert {

    // this enum define the last level of processing the packet reached in the
// channel
enum MeasurementProfileProcessStatus {
  NoStatus,
  Acquired,
  Pushed,
  Popped,
  Executed,
  Dropped
};
class MeasurementProfileBase {
 public:
  bool IsOptionalUserProfile;
  MeasurementProfileProcessStatus processState; 

  MeasurementProfileBase(bool isOptionalUserProfile) {
    IsOptionalUserProfile = isOptionalUserProfile;
  }

  // must
};
}  // namespace pipert
#endif