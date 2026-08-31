#include "GamingStation.h"
#include "EventNotice.h"
#include <iostream>

GamingStation::GamingStation() : EventUnit("Gaming Station", 40) {}

void GamingStation::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void GamingStation::onSafetyAlert() {
    std::cout << "  Gaming Station: stops accepting players and saves the current session." << std::endl;
}
