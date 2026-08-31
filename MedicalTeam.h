#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H

#include "EventUnit.h"

class MedicalTeam : public EventUnit {
    public:
        MedicalTeam();
        void update(const EventNotice& notice) override;
        void onSafetyAlert() override;
        void onCapacityAlert() override;
        void onEvacuate() override;

};

#endif
