#include "TechnicalSupport.h"
#include "EventNotice.h"
#include <iostream>

TechnicalSupport::TechnicalSupport() : EventUnit("Technical Support", 20) {}

void TechnicalSupport::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::SERVER_OUTAGE:
            std::cout << "  Technical Support: investigates and attempts to restore the server." << std::endl;
            break;
        default:
            std::cout << "  Technical Support: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
