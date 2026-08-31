#ifndef CHECKINDESK_H
#define CHECKINDESK_H

#include "EventUnit.h"

class CheckInDesk : public EventUnit {
    public:
        CheckInDesk();
        void update(const EventNotice& notice) override;
        void onCapacityAlert() override;

};

#endif
