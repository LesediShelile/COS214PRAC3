#include "BadgeStation.h"
#include "EventNotice.h"
#include <iostream>

BadgeStation::BadgeStation() : EventUnit("Badge Station", 30) {}

void BadgeStation::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::CAPACITY_ALERT:
            close(); std::cout << "  Badge Station: pauses new badge printing to reduce the registration queue." << std::endl; break;
        case NoticeType::CLOSE_AREA:
            close(); std::cout << "  Badge Station: closes the badge counter." << std::endl; break;
        case NoticeType::OPEN_AREA:
        case NoticeType::RESUME:
            open(); std::cout << "  Badge Station: resumes badge service." << std::endl; break;
        default: std::cout << "  Badge Station: acknowledges " << notice.getTypeName() << "." << std::endl; break;
    }
}
