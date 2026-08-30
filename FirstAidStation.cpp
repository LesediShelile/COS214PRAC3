#include "FirstAidStation.h"
#include "EventNotice.h"
#include <iostream>

FirstAidStation::FirstAidStation() : EventUnit("First Aid Station", 8) {}

void FirstAidStation::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::EVACUATE:
        case NoticeType::SAFETY_ALERT:
            std::cout << "  First Aid Station: remains operational and prepares to assist attendees." << std::endl;
            break;
        default:
            std::cout << "  First Aid Station: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
