#ifndef GAMINGSTATION_H
#define GAMINGSTATION_H

#include "EventUnit.h"

class GamingStation : public EventUnit {
    public:
        GamingStation();
        void update(const EventNotice& notice) override;
        void onSafetyAlert() override;
};

#endif