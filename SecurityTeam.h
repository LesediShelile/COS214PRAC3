#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include "EventUnit.h"

class SecurityTeam : public EventUnit {
    public:
        SecurityTeam();
        void update(const EventNotice& notice) override;
};

#endif
