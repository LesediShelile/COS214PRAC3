#ifndef SECURITYAREA_H
#define SECURITYAREA_H

#include "EventGroup.h"

/**
 * @brief Concrete EventGroup named SecurityArea.
 *
 * SecurityArea participates as a Composite node in the GameVerse ownership tree.
 */
class SecurityArea : public EventGroup {
    public:
        /** @brief Constructs this SecurityArea. */
        SecurityArea();
};

#endif
