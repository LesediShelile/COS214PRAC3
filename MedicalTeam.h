#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named MedicalTeam.
 *
 * MedicalTeam participates as a Leaf in the Composite pattern and Observer participant.
 */
class MedicalTeam : public EventUnit {
    public:
        /** @brief Constructs this MedicalTeam. */
        MedicalTeam();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onSafetyAlert() override;
        void onCapacityAlert() override;
        void onEvacuate() override;

};

#endif
