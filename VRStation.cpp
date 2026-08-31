#include "VRStation.h"
#include "EventNotice.h"
#include <iostream>

VRStation::VRStation() : EventUnit("VR Station", 4) {}

void VRStation::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void VRStation::onCapacityAlert() {
    std::cout << "  VR Station: stops accepting new users but allows the current session to finish." << std::endl;
}

void VRStation::onEvacuate() {
    std::cout << "  VR Station: safely shuts down the VR equipment." << std::endl;
}
