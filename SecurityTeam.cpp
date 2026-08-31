#include "SecurityTeam.h"
#include "EventNotice.h"
#include <iostream>

SecurityTeam::SecurityTeam() : EventUnit("Security Team", 20) {}

void SecurityTeam::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void SecurityTeam::onSafetyAlert() {
    std::cout << "  Security Team: secures the affected area and controls attendee movement." << std::endl;
}

void SecurityTeam::onEvacuate() {
    std::cout << "  Security Team: directs attendees toward designated exits." << std::endl;
}
