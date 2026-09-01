#ifndef VRZONE_H
#define VRZONE_H

#include "EventGroup.h"

/**
 * @brief Concrete EventGroup named VRZone.
 *
 * VRZone participates as a Composite node in the GameVerse ownership tree.
 */
class VRZone : public EventGroup {
    public:
        /** @brief Constructs this VRZone. */
        VRZone();
};

#endif
