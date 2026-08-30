#include "SafetyTeam.h"
#include "EventNotice.h"
#include <iostream>

SafetyTeam::SafetyTeam() : EventUnit("Safety Team", 10) {}

void SafetyTeam::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::SAFETY_ALERT:
        case NoticeType::EVACUATE:
            std::cout << "  Safety Team: monitors the VR Zone and assists attendees to safety." << std::endl;
            break;
        default:
            std::cout << "  Safety Team: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
