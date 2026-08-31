#include "FirstAidStation.h"
#include "EventNotice.h"
#include <iostream>

FirstAidStation::FirstAidStation() : EventUnit("First Aid Station", 8) {}

void FirstAidStation::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void FirstAidStation::onSafetyAlert() {
    std::cout << "  First Aid Station: remains operational and prepares to assist attendees." << std::endl;
}

void FirstAidStation::onEvacuate() {
    std::cout << "  First Aid Station: remains operational and prepares to assist attendees." << std::endl;
}
