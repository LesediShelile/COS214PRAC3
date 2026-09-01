#include "VIPSupport.h"
#include "EventNotice.h"
#include <iostream>

VIPSupport::VIPSupport() : EventUnit("VIP Support", 25) {}

void VIPSupport::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void VIPSupport::onEvacuate() {
    std::cout << "  VIP Support: escorts VIP guests to the designated evacuation route." << std::endl;
}
