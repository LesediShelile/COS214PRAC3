#ifndef ESPORTSHALL_H
#define ESPORTSHALL_H

#include "EventGroup.h"

/**
 * @brief Concrete EventGroup named EsportsHall.
 *
 * EsportsHall participates as a Composite node in the GameVerse ownership tree.
 */
class EsportsHall : public EventGroup {
    public:
        /** @brief Constructs this EsportsHall. */
        EsportsHall();
};

#endif
