#include "MedicalTeam.h"
#include "EventNotice.h"
#include <iostream>

MedicalTeam::MedicalTeam() : EventUnit("Medical Team") {}

void MedicalTeam::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::SAFETY_ALERT:
            std::cout << "  Medical Team: remains operational and prepares to assist attendees." << std::endl;
            break;
        case NoticeType::CAPACITY_ALERT:
            std::cout << "  Medical Team: remains operational because medical capacity is not affected by attendee admission." << std::endl;
            break;
        case NoticeType::EVACUATE:
            std::cout << "  Medical Team: remains active and prepares for potential injuries." << std::endl;
            break;
        default:
            std::cout << "  Medical Team: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
