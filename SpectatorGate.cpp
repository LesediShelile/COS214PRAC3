#include "SpectatorGate.h"
#include "EventNotice.h"
#include <iostream>

SpectatorGate::SpectatorGate() : EventUnit("Spectator Gate", 1000) {}

void SpectatorGate::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::CAPACITY_ALERT:
            std::cout << "  Spectator Gate: stops admitting additional spectators." << std::endl;
            break;
        case NoticeType::SERVER_OUTAGE:
            std::cout << "  Spectator Gate: remains open unless the resulting crowd reaches the capacity threshold." << std::endl;
            break;
        default:
            std::cout << "  Spectator Gate: acknowledges " << notice.getType() << "." << std::endl;
            break;
    }
}
