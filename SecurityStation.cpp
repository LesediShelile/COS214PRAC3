#include "SecurityStation.h"
#include "EventNotice.h"
#include <iostream>

SecurityStation::SecurityStation() : EventUnit("Security Station") {}

void SecurityStation::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::CAPACITY_ALERT:
            std::cout << "  Security Station: sends security personnel to manage the queue." << std::endl;
            break;
        default:
            std::cout << "  Security Station: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
