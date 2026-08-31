#ifndef CREATORLOUNGE_H
#define CREATORLOUNGE_H

#include "EventGroup.h"

/**
 * @brief Concrete EventGroup named CreatorLounge.
 *
 * CreatorLounge participates as a Composite node in the GameVerse ownership tree.
 */
class CreatorLounge : public EventGroup {
    public:
        /** @brief Constructs this CreatorLounge. */
        CreatorLounge();
};

#endif
