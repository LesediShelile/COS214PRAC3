#ifndef VIPAREA_H
#define VIPAREA_H

#include "EventGroup.h"

/**
 * @brief Concrete EventGroup named VIPArea.
 *
 * VIPArea participates as a Composite node in the GameVerse ownership tree.
 */
class VIPArea : public EventGroup {
    public:
        /** @brief Constructs this VIPArea. */
        VIPArea();
};

#endif
