#include "InformationDesk.h"
#include "EventNotice.h"
#include <iostream>

InformationDesk::InformationDesk() : EventUnit("Information Desk", 5) {}

void InformationDesk::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "  Information Desk: publishes the revised schedule." << std::endl; break;
        case NoticeType::SERVER_OUTAGE:
            std::cout << "  Information Desk: tells attendees that affected matches are delayed." << std::endl; break;
        case NoticeType::EVACUATE:
            std::cout << "  Information Desk: directs attendees to the nearest safe exit." << std::endl; break;
        default: std::cout << "  Information Desk: acknowledges " << notice.getTypeName() << "." << std::endl; break;
    }
}
