#include "MedicalTeam.h"
#include "EventNotice.h"
#include <iostream>

MedicalTeam::MedicalTeam() : EventUnit("Medical Team", 10) {}

void MedicalTeam::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::WEATHER_ALERT:
        case NoticeType::EVACUATE:
            open(); std::cout << "  Medical Team: remains active and prepares to assist attendees." << std::endl; break;
        case NoticeType::CAPACITY_ALERT:
            std::cout << "  Medical Team: remains operational; medical capacity is managed separately." << std::endl; break;
        default: std::cout << "  Medical Team: acknowledges " << notice.getTypeName() << "." << std::endl; break;
    }
}
