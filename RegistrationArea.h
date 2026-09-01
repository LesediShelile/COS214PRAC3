#ifndef REGISTRATIONAREA_H
#define REGISTRATIONAREA_H

#include "EventGroup.h"

/**
 * @brief Concrete EventGroup named RegistrationArea.
 *
 * RegistrationArea participates as a Composite node in the GameVerse ownership tree.
 */
class RegistrationArea : public EventGroup {
    public:
        /** @brief Constructs this RegistrationArea. */
        RegistrationArea();
};

#endif
