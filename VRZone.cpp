#include "VRZone.h"
#include "VRStation.h"
#include "SafetyTeam.h"

VRZone::VRZone() : EventGroup("VR Zone") {
    add(new VRStation());
    add(new SafetyTeam());
}
