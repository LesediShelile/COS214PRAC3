#include "InformationDesk.h"
#include "EventNotice.h"
#include <iostream>

InformationDesk::InformationDesk() : EventUnit("Information Desk") {}

void InformationDesk::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::SERVER_OUTAGE:
            std::cout << "  Information Desk: informs attendees that the tournament has been delayed." << std::endl;
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "  Information Desk: updates the information available to attendees." << std::endl;
            break;
        default:
            std::cout << "  Information Desk: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
