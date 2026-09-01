#include "SpectatorGate.h"
#include "EventNotice.h"
#include <iostream>

SpectatorGate::SpectatorGate() : EventUnit("Spectator Gate", 1000) {}

void SpectatorGate::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void SpectatorGate::onCapacityAlert() {
    std::cout << "  Spectator Gate: stops admitting additional spectators." << std::endl;
}

void SpectatorGate::onServerOutage() {
    std::cout << "  Spectator Gate: remains open unless the resulting crowd reaches the capacity threshold." << std::endl;
}
