#ifndef _CHANNELIMPL_H_
#define _CHANNELIMPL_H_

#include <utility>

#include "pipert/PacketBase.h"
#include "pipert/Timer.h"
namespace pipert {

template <class T>
class MeasurementProfileBase {
 public:
  bool IsOptionalUserProfile;

  MeasurementProfileBase(bool isOptionalUserProfile) {
    IsOptionalUserProfile = isOptionalUserProfile;
  }

  // must
};
}  // namespace pipert
#endif