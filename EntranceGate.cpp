#include "EntranceGate.h"
#include "EventNotice.h"
#include <iostream>

EntranceGate::EntranceGate() : EventUnit("Entrance Gate", 1000) {}

void EntranceGate::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::EVACUATE:
            std::cout << "  Entrance Gate: switches to emergency-exit mode and permits people to leave." << std::endl;
            break;
        default:
            std::cout << "  Entrance Gate: acknowledges " << notice.getType() << "." << std::endl;
            break;
    }
}
