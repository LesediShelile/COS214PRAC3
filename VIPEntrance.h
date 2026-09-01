#ifndef VIPENTRANCE_H
#define VIPENTRANCE_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit responsible for controlling VIP entry.
 *
 * VIPEntrance participates as a Leaf in the Composite pattern and as an
 * Observer in the Observer pattern. It controls access to VIP areas and
 * reacts to safety and evacuation notices.
 */
class VIPEntrance : public EventUnit {
public:
    /**
     * @brief Constructs the VIP Entrance.
     */
    VIPEntrance();

    /**
     * @brief Reacts to a pushed event notice.
     *
     * @param notice Notice received from a Subject.
     */
    void update(const EventNotice& notice) override;

    /**
     * @brief Responds to a safety alert.
     */
    void onSafetyAlert() override;

    /**
     * @brief Responds to an evacuation instruction.
     */
    void onEvacuate() override;

    /**
     * @brief Responds to an area closing notice.
     */
    void onCloseArea() override;
};

#endif