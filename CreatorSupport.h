#ifndef CREATORSUPPORT_H
#define CREATORSUPPORT_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named CreatorSupport.
 *
 * CreatorSupport participates as a Leaf in the Composite pattern and Observer participant.
 */
class CreatorSupport : public EventUnit {
    public:
        /** @brief Constructs this CreatorSupport. */
        CreatorSupport();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;

};

#endif
