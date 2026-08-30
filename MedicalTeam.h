#ifndef MEDICALTEAM_H
#define MEDICALTEAM_H

#include "EventUnit.h"

/** @brief Gaming-convention leaf responsible for Medical Team. */
class MedicalTeam : public EventUnit {
public:
    /** @brief Constructs the Medical Team. */
    MedicalTeam();
    /** @brief Applies this unit's polymorphic response to a notice. @param notice Notice received. */
    void update(const EventNotice& notice) override;
};

#endif
