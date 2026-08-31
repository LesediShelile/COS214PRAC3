#include "VIPCheckIn.h"
#include "EventNotice.h"
#include <iostream>

VIPCheckIn::VIPCheckIn() : EventUnit("VIP Check-In", 100) {}

void VIPCheckIn::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void VIPCheckIn::onSafetyAlert() {
    std::cout << "  VIP Check-In: temporarily restricts VIP access." << std::endl;
}

void VIPCheckIn::onEvacuate() {
    std::cout << "  VIP Check-In: stops admitting VIP guests and directs them toward the evacuation route." << std::endl;
}

void VIPCheckIn::onScheduleChange() {
    std::cout << "  VIP Check-In: updates VIP guests about affected activities." << std::endl;
}
