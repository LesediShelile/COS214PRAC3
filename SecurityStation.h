#ifndef SECURITYSTATION_H
#define SECURITYSTATION_H

#include "EventUnit.h"

class SecurityStation : public EventUnit {
    public:
        SecurityStation();
        void update(const EventNotice& notice) override;
};

#endif
