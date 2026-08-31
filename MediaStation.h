#ifndef MEDIASTATION_H
#define MEDIASTATION_H

#include "EventUnit.h"

class MediaStation : public EventUnit {
    public:
        MediaStation();
        void update(const EventNotice& notice) override;
        void onServerOutage() override;

};

#endif
