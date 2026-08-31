#include "BadgeStation.h"
#include "EventNotice.h"
#include <iostream>

BadgeStation::BadgeStation()
    : EventUnit("Badge Station", 150) {}

void BadgeStation::update(const EventNotice& notice) {
    std::cout << "  Badge Station: acknowledges "
              << notice.getType() << "." << std::endl;
}