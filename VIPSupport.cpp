#include "VIPSupport.h"
#include "EventNotice.h"
#include <iostream>

VIPSupport::VIPSupport() : EventUnit("VIP Support", 25) {}

void VIPSupport::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::EVACUATE:
            std::cout << "  VIP Support: escorts VIP guests to the designated evacuation route." << std::endl;
            break;
        default:
            std::cout << "  VIP Support: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
