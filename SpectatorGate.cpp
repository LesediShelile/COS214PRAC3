#include "SpectatorGate.h"
#include "EventNotice.h"
#include <iostream>

SpectatorGate::SpectatorGate() : EventUnit("Spectator Gate", 500) {}

void SpectatorGate::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::CAPACITY_ALERT:
            std::cout << "  Spectator Gate: stops admitting spectators until capacity is safe." << std::endl; break;
        case NoticeType::EVACUATE:
            std::cout << "  Spectator Gate: becomes an exit and guides spectators out." << std::endl; break;
        default: std::cout << "  Spectator Gate: acknowledges " << notice.getTypeName() << "." << std::endl; break;
    }
}
