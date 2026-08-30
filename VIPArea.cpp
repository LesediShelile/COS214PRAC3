#include "VIPArea.h"
#include "VIPCheckIn.h"
#include "VIPSupport.h"

VIPArea::VIPArea() : EventGroup("VIP Services") {
    add(new VIPCheckIn());
    add(new VIPSupport());
}
