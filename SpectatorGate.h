#ifndef SPECTATORGATE_H
#define SPECTATORGATE_H

#include "EventUnit.h"

/** @brief Gaming-convention leaf responsible for Spectator Gate. */
class SpectatorGate : public EventUnit {
public:
    /** @brief Constructs the Spectator Gate. */
    SpectatorGate();
    /** @brief Applies this unit's polymorphic response to a notice. @param notice Notice received. */
    void update(const EventNotice& notice) override;
};

#endif
