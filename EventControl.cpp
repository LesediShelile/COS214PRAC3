#include "EventControl.h"
#include <stdexcept>
#include <iostream>

EventControl::EventControl() : currentNotice() {}

void EventControl::issueNotice(NoticeType type, const std::string& message) {
    currentNotice.reset(new EventNotice(type, message));
    std::cout << "\n=== " << currentNotice->getTypeName() << " ===\n"
              << currentNotice->getMessage() << std::endl;
    notify(*currentNotice);
}

const EventNotice& EventControl::getCurrentNotice() const {
    if (!currentNotice.get()) throw std::logic_error("No notice has been issued.");
    return *currentNotice;
}
