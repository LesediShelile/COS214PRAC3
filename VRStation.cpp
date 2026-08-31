#include "VRStation.h"
#include "EventNotice.h"
#include <iostream>

VRStation::VRStation() : EventUnit("VR Station", 4) {}

void VRStation::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::CAPACITY_ALERT:
            std::cout << "  VR Station: stops accepting new users but allows the current session to finish." << std::endl;
            break;
        case NoticeType::EVACUATE:
            std::cout << "  VR Station: safely shuts down the VR equipment." << std::endl;
            break;
        default:
            std::cout << "  VR Station: acknowledges " << notice.getType() << "." << std::endl;
            break;
    }
}
