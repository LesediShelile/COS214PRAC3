#include "CheckInDesk.h"
#include "EventNotice.h"
#include <iostream>

CheckInDesk::CheckInDesk() : EventUnit("Check-In Desk", 200) {}

void CheckInDesk::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void CheckInDesk::onCapacityAlert() {
    std::cout << "  Check-In Desk: temporarily stops registering new attendees." << std::endl;
}
