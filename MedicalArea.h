#ifndef MEDICALAREA_H
#define MEDICALAREA_H

#include "EventGroup.h"

/**
 * @brief Concrete EventGroup named MedicalArea.
 *
 * MedicalArea participates as a Composite node in the GameVerse ownership tree.
 */
class MedicalArea : public EventGroup {
    public:
        /** @brief Constructs this MedicalArea. */
        MedicalArea();
};

#endif
