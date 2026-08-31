#ifndef SAFETYTEAM_H
#define SAFETYTEAM_H

#include "EventUnit.h"

class SafetyTeam : public EventUnit {
    public:
        SafetyTeam();
        void update(const EventNotice& notice) override;
        void onSafetyAlert() override;
        void onEvacuate() override;

};

#endif
