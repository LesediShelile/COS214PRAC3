#ifndef BADGESTATION_H
#define BADGESTATION_H

#include "EventUnit.h"

class BadgeStation : public EventUnit {
    public:
        BadgeStation();
        void update(const EventNotice& notice) override;
};

#endif
