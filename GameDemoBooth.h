#ifndef GAMEDEMOBOOTH_H
#define GAMEDEMOBOOTH_H

#include "EventUnit.h"

class GameDemoBooth : public EventUnit {
    public:
        GameDemoBooth();
        void update(const EventNotice& notice) override;
        void onScheduleChange() override;

};

#endif
