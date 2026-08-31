#include "MedicalTeam.h"
#include "EventNotice.h"
#include <iostream>

MedicalTeam::MedicalTeam() : EventUnit("Medical Team", 12) {}

void MedicalTeam::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void MedicalTeam::onSafetyAlert() {
    std::cout << "  Medical Team: remains operational and prepares to assist attendees." << std::endl;
}

void MedicalTeam::onCapacityAlert() {
    std::cout << "  Medical Team: remains operational because medical capacity is not affected by attendee admission." << std::endl;
}

void MedicalTeam::onEvacuate() {
    std::cout << "  Medical Team: remains active and prepares for potential injuries." << std::endl;
}
