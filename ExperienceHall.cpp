#include "ExperienceHall.h"
#include "VRZone.h"
#include "DemoZone.h"

ExperienceHall::ExperienceHall() : EventGroup("VR & Experience Hall") {
    add(new VRZone());
    add(new DemoZone());
}
