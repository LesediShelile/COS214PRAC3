#include "MediaStation.h"
#include "EventNotice.h"
#include <iostream>

MediaStation::MediaStation() : EventUnit("Media Station", 20) {}

void MediaStation::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::SERVER_OUTAGE:
            std::cout << "  Media Station: pauses streaming/recording equipment until the server is restored." << std::endl;
            break;
        default:
            std::cout << "  Media Station: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
