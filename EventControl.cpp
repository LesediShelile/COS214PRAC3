#include "EventControl.h"
#include <iostream>
#include <stdexcept>

EventControl::EventControl() : currentNotice() {}

void EventControl::issueNotice(EventNotice* notice) {
    if (notice == 0) return;
    currentNotice.reset(notice);
    std::cout << "\n=== EventControl issues " << currentNotice->getType() << " ===" << std::endl;
    if (!currentNotice->getMessage().empty()) {
        std::cout << currentNotice->getMessage() << std::endl;
    }
    notify(*currentNotice);
}

const EventNotice& EventControl::getCurrentNotice() const {
    if (!currentNotice) throw std::logic_error("EventControl has not issued a notice yet.");
    return *currentNotice;
}
