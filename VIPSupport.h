#ifndef VIPSUPPORT_H
#define VIPSUPPORT_H

#include "EventUnit.h"

class VIPSupport : public EventUnit {
    public:
        VIPSupport();
        void update(const EventNotice& notice) override;
};

#endif
