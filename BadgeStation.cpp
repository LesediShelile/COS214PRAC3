#include "BadgeStation.h"
#include "EventNotice.h"
#include <iostream>

BadgeStation::BadgeStation() : EventUnit("Badge Station") {}

void BadgeStation::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::CLOSE_AREA:
            std::cout << "  Badge Station: stops printing badges and closes the counter." << std::endl;
            break;
        default:
            std::cout << "  Badge Station: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
