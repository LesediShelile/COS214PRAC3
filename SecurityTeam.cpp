#include "SecurityTeam.h"
#include "EventNotice.h"
#include <iostream>

SecurityTeam::SecurityTeam() : EventUnit("Security Team", 20) {}

void SecurityTeam::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::SAFETY_ALERT:
            std::cout << "  Security Team: secures the affected area and controls attendee movement." << std::endl;
            break;
        case NoticeType::EVACUATE:
            std::cout << "  Security Team: directs attendees toward designated exits." << std::endl;
            break;
        default:
            std::cout << "  Security Team: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
