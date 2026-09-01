#ifndef CONVENTION_H
#define CONVENTION_H

#include "EventGroup.h"

// Convention is the root Composite node ("GameVerse Convention"). Like every
// other EventGroup it is a pure composite - it does not build its own
// children and it does not own the EventControl. Assembling the tree and
// driving EventControl is the Client's job (main.cpp).
/**
 * @brief Concrete EventGroup named Convention.
 *
 * Convention participates as a Composite node in the GameVerse ownership tree.
 */
class Convention : public EventGroup {
    public:
        /** @brief Constructs this Convention. */
        Convention();
};

#endif
