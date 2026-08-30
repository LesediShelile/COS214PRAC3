#include "EventControl.h"
#include <iostream>
#include <stdexcept>

EventControl::EventControl() : currentNotice(nullptr) {}

void EventControl::issueNotice(NoticeType type, const std::string& message) {
    // Holds onto the current notice as its state, then pushes it to observers.
    currentNotice = std::make_unique<EventNotice>(type, message);

    std::cout << "\n=== EventControl issues " << currentNotice->getTypeName() << " ===" << std::endl;
    notify(*currentNotice);
}

const EventNotice& EventControl::getCurrentNotice() const {
    if (!currentNotice) {
        throw std::logic_error("EventControl has not issued a notice yet.");
    }
    return *currentNotice;
}
