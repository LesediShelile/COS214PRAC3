#ifndef GAMINGSTATION_H
#define GAMINGSTATION_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named GamingStation.
 *
 * GamingStation participates as a Leaf in the Composite pattern and Observer participant.
 */
class GamingStation : public EventUnit {
    public:
        /** @brief Constructs this GamingStation. */
        GamingStation();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onSafetyAlert() override;
};

#endif