#ifndef ENTRANCEGATE_H
#define ENTRANCEGATE_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named EntranceGate.
 *
 * EntranceGate participates as a Leaf in the Composite pattern and Observer participant.
 */
class EntranceGate : public EventUnit {
    public:
        /** @brief Constructs this EntranceGate. */
        EntranceGate();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onEvacuate() override;

};

#endif
