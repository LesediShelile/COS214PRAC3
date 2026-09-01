#ifndef OPERATIONSAREA_H
#define OPERATIONSAREA_H

#include "EventGroup.h"

/**
 * @brief Concrete EventGroup named OperationsArea.
 *
 * OperationsArea participates as a Composite node in the GameVerse ownership tree.
 */
class OperationsArea : public EventGroup {
    public:
        /** @brief Constructs this OperationsArea. */
        OperationsArea();
};

#endif
