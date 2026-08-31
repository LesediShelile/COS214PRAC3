#ifndef TECHNICALSUPPORT_H
#define TECHNICALSUPPORT_H

#include "EventUnit.h"

class TechnicalSupport : public EventUnit {
    public:
        TechnicalSupport();
        void update(const EventNotice& notice) override;
        void onServerOutage() override;

};

#endif
