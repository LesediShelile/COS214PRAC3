#include "SecurityTeam.h"
#include "EventNotice.h"
#include <iostream>

SecurityTeam::SecurityTeam() : EventUnit("Security Team", 15) {}

void SecurityTeam::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::CAPACITY_ALERT:
            std::cout << "  Security Team: deploys staff to control queues." << std::endl; break;
        case NoticeType::WEATHER_ALERT:
            std::cout << "  Security Team: redirects attendees away from exposed areas." << std::endl; break;
        case NoticeType::EVACUATE:
            std::cout << "  Security Team: controls movement and keeps evacuation routes clear." << std::endl; break;
        default: std::cout << "  Security Team: acknowledges " << notice.getTypeName() << "." << std::endl; break;
    }
}
