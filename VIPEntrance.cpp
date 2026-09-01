#include "VIPEntrance.h"

#include "EventNotice.h"

#include <iostream>

/**
 * @brief Constructs the VIP Entrance with its event name and capacity.
 */
VIPEntrance::VIPEntrance()
    : EventUnit("VIP Entrance", 200) {
}

/**
 * @brief Receives and dispatches a pushed event notice.
 *
 * @param notice Notice received from a Subject.
 */
void VIPEntrance::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

/**
 * @brief Restricts VIP access during a safety alert.
 */
void VIPEntrance::onSafetyAlert() {
    std::cout
        << "  VIP Entrance: temporarily restricts entry and checks "
        << "VIP guests before allowing access."
        << std::endl;
}

/**
 * @brief Switches the entrance to an emergency exit route.
 */
void VIPEntrance::onEvacuate() {
    std::cout
        << "  VIP Entrance: stops VIP entry and directs guests "
        << "towards the designated evacuation route."
        << std::endl;
}

/**
 * @brief Stops admitting VIP guests when the area closes.
 */
void VIPEntrance::onCloseArea() {
    std::cout
        << "  VIP Entrance: stops admitting VIP guests and closes "
        << "access to the VIP area."
        << std::endl;
}