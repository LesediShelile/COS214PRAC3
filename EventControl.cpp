#include "EventControl.h"
#include <iostream>
#include <stdexcept>

EventControl::EventControl() : currentNotice() {}

void EventControl::issueNotice(NoticeType type, const std::string& message) {
    currentNotice.reset(new EventNotice(type, message));
    std::cout << "\n=== EventControl issues " << currentNotice->getTypeName() << " ===" << std::endl;
    notify(*currentNotice);
}

const EventNotice& EventControl::getCurrentNotice() const {
    if (!currentNotice) {
        throw std::logic_error("EventControl has not issued a notice yet.");
    }
    return *currentNotice;
}
