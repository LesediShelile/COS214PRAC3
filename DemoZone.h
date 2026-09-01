#ifndef DEMOZONE_H
#define DEMOZONE_H

#include "EventGroup.h"

/**
 * @brief Concrete EventGroup named DemoZone.
 *
 * DemoZone participates as a Composite node in the GameVerse ownership tree.
 */
class DemoZone : public EventGroup {
    public:
        /** @brief Constructs this DemoZone. */
        DemoZone();
};

#endif
