#include "BadgeStation.h"
#include "EventNotice.h"
#include <iostream>

BadgeStation::BadgeStation() : EventUnit("Badge Station", 150) {}

void BadgeStation::update(const EventNotice& notice) {
    notice.dispatch(*this);
}
