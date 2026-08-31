#include "InformationDesk.h"
#include "EventNotice.h"
#include <iostream>

InformationDesk::InformationDesk() : EventUnit("Information Desk", 80) {}

void InformationDesk::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void InformationDesk::onServerOutage() {
    std::cout << "  Information Desk: informs attendees that the tournament has been delayed." << std::endl;
}

void InformationDesk::onScheduleChange() {
    std::cout << "  Information Desk: updates the information available to attendees." << std::endl;
}
