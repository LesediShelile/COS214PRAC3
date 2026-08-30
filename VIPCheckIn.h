#ifndef VIPCHECKIN_H
#define VIPCHECKIN_H

#include "EventUnit.h"

class VIPCheckIn : public EventUnit {
    public:
        VIPCheckIn();
        void update(const EventNotice& notice) override;
};

#endif
