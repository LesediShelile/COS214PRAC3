#include "SafetyTeam.h"
#include "EventNotice.h"
#include <iostream>

SafetyTeam::SafetyTeam() : EventUnit("Safety Team", 10) {}

void SafetyTeam::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void SafetyTeam::onSafetyAlert() {
    std::cout << "  Safety Team: monitors the affected area and assists attendees to safety." << std::endl;
}

void SafetyTeam::onEvacuate() {
    std::cout << "  Safety Team: assists attendees to safety." << std::endl;
}
