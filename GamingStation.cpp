#include "GamingStation.h"
#include "EventNotice.h"
#include <iostream>

GamingStation::GamingStation() : EventUnit("Gaming Station") {}

void GamingStation::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::SAFETY_ALERT:
            std::cout << "  Gaming Station: stops accepting players and saves the current session." << std::endl;
            break;
        default:
            std::cout << "  Gaming Station: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
