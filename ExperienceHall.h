#ifndef EXPERIENCEHALL_H
#define EXPERIENCEHALL_H

#include "EventGroup.h"

/**
 * @brief Concrete EventGroup named ExperienceHall.
 *
 * ExperienceHall participates as a Composite node in the GameVerse ownership tree.
 */
class ExperienceHall : public EventGroup {
    public:
        /** @brief Constructs this ExperienceHall. */
        ExperienceHall();
};

#endif
