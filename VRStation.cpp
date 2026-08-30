#include "VRStation.h"
#include "EventNotice.h"
#include <iostream>

VRStation::VRStation() : EventUnit("VR Station", 20) {}

void VRStation::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::WEATHER_ALERT:
            close(); std::cout << "  VR Station: pauses sessions because this station is in an exposed area." << std::endl; break;
        case NoticeType::CAPACITY_ALERT:
            std::cout << "  VR Station: stops admitting new players but lets current sessions finish." << std::endl; break;
        case NoticeType::EVACUATE:
            close(); std::cout << "  VR Station: safely powers down headsets." << std::endl; break;
        default: std::cout << "  VR Station: acknowledges " << notice.getTypeName() << "." << std::endl; break;
    }
}
