#include "AnnouncementBoard.h"
#include "EventNotice.h"
#include <iostream>

AnnouncementBoard::AnnouncementBoard() {}

void AnnouncementBoard::update(const EventNotice& notice) {
    std::string prefix;
    switch (notice.getSeverity()) {
        case EventNotice::Severity::HIGH:
            prefix = "URGENT ANNOUNCEMENT";
            break;
        case EventNotice::Severity::MEDIUM:
            prefix = "Announcement";
            break;
        case EventNotice::Severity::LOW:
        default:
            prefix = "Notice";
            break;
    }

    std::cout << "  [Announcement Board] " << prefix << " (" << notice.getType() << "): ";
    if (!notice.getMessage().empty()) {
        std::cout << notice.getMessage();
    } else {
        std::cout << "Please follow instructions from convention staff.";
    }
    std::cout << std::endl;
}
