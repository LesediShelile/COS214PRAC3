#include "VIPCheckIn.h"
#include "EventNotice.h"
#include <iostream>

VIPCheckIn::VIPCheckIn() : EventUnit("VIP Check-In") {}

void VIPCheckIn::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::SAFETY_ALERT:
            std::cout << "  VIP Check-In: temporarily restricts VIP access." << std::endl;
            break;
        case NoticeType::EVACUATE:
            std::cout << "  VIP Check-In: stops admitting VIP guests and directs them toward the evacuation route." << std::endl;
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "  VIP Check-In: updates VIP guests about affected activities." << std::endl;
            break;
        default:
            std::cout << "  VIP Check-In: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
