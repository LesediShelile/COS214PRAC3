#ifndef REFEREETEAM_H
#define REFEREETEAM_H

#include "EventUnit.h"

class RefereeTeam : public EventUnit {
    public:
        RefereeTeam();
        void update(const EventNotice& notice) override;
        void onServerOutage() override;
        void onScheduleChange() override;

};

#endif
