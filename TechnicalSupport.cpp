#include "TechnicalSupport.h"
#include "EventNotice.h"
#include <iostream>

TechnicalSupport::TechnicalSupport() : EventUnit("Technical Support", 20) {}

void TechnicalSupport::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void TechnicalSupport::onServerOutage() {
    std::cout << "  Technical Support: investigates and attempts to restore the server." << std::endl;
}
