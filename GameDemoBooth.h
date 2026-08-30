#ifndef GAMEDEMOBOOTH_H
#define GAMEDEMOBOOTH_H

#include "EventUnit.h"

/** @brief Gaming-convention leaf responsible for Game Demo Booth. */
class GameDemoBooth : public EventUnit {
public:
    /** @brief Constructs the Game Demo Booth. */
    GameDemoBooth();
    /** @brief Applies this unit's polymorphic response to a notice. @param notice Notice received. */
    void update(const EventNotice& notice) override;
};

#endif
