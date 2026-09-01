#ifndef GAMEDEMOBOOTH_H
#define GAMEDEMOBOOTH_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named GameDemoBooth.
 *
 * GameDemoBooth participates as a Leaf in the Composite pattern and Observer participant.
 */
class GameDemoBooth : public EventUnit {
    public:
        /** @brief Constructs this GameDemoBooth. */
        GameDemoBooth();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onScheduleChange() override;

};

#endif
