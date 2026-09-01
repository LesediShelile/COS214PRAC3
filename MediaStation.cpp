#include "MediaStation.h"
#include "EventNotice.h"
#include <iostream>

MediaStation::MediaStation() : EventUnit("Media Station", 20) {}

void MediaStation::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void MediaStation::onServerOutage() {
    std::cout << "  Media Station: pauses streaming/recording equipment until the server is restored." << std::endl;
}
