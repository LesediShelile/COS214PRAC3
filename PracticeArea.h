#ifndef PRACTICEAREA_H
#define PRACTICEAREA_H

#include "EventGroup.h"

/**
 * @brief Concrete EventGroup named PracticeArea.
 *
 * PracticeArea participates as a Composite node in the GameVerse ownership tree.
 */
class PracticeArea : public EventGroup {
    public:
        /** @brief Constructs this PracticeArea. */
        PracticeArea();
};

#endif
