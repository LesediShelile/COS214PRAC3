#ifndef BADGESTATION_H
#define BADGESTATION_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named BadgeStation.
 *
 * BadgeStation participates as a Leaf in the Composite pattern and Observer participant.
 */
class BadgeStation : public EventUnit {
    public:
        /** @brief Constructs this BadgeStation. */
        BadgeStation();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
};

#endif
