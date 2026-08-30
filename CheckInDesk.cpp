#include "CheckInDesk.h"
#include "EventNotice.h"
#include <iostream>

CheckInDesk::CheckInDesk() : EventUnit("Check-In Desk", 200) {}

void CheckInDesk::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::CAPACITY_ALERT:
            std::cout << "  Check-In Desk: temporarily stops registering new attendees." << std::endl;
            break;
        default:
            std::cout << "  Check-In Desk: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
