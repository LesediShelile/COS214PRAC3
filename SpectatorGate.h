#ifndef SPECTATORGATE_H
#define SPECTATORGATE_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named SpectatorGate.
 *
 * SpectatorGate participates as a Leaf in the Composite pattern and Observer participant.
 */
class SpectatorGate : public EventUnit {
    public:
        /** @brief Constructs this SpectatorGate. */
        SpectatorGate();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onCapacityAlert() override;
        void onServerOutage() override;

};

#endif
