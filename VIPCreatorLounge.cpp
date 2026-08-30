#include "VIPCreatorLounge.h"
#include "VIPArea.h"
#include "CreatorLounge.h"

VIPCreatorLounge::VIPCreatorLounge() : EventGroup("VIP & Creator Lounge") {
    add(new VIPArea());
    add(new CreatorLounge());
}
