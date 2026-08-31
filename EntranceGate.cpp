#include "EntranceGate.h"
#include "EventNotice.h"
#include <iostream>

EntranceGate::EntranceGate() : EventUnit("Entrance Gate", 1000) {}

void EntranceGate::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void EntranceGate::onEvacuate() {
    std::cout << "  Entrance Gate: switches to emergency-exit mode and permits people to leave." << std::endl;
}
