#include "SecurityStation.h"
#include "EventNotice.h"
#include <iostream>

SecurityStation::SecurityStation() : EventUnit("Security Station", 20) {}

void SecurityStation::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void SecurityStation::onCapacityAlert() {
    std::cout << "  Security Station: sends security personnel to manage the queue." << std::endl;
}
