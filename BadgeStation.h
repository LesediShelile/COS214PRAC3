#ifndef BADGESTATION_H
#define BADGESTATION_H

#include "EventUnit.h"

/** @brief Gaming-convention leaf responsible for Badge Station. */
class BadgeStation : public EventUnit {
public:
    /** @brief Constructs the Badge Station. */
    BadgeStation();
    /** @brief Applies this unit's polymorphic response to a notice. @param notice Notice received. */
    void update(const EventNotice& notice) override;
};

#endif
