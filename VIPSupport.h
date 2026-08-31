#ifndef VIPSUPPORT_H
#define VIPSUPPORT_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named VIPSupport.
 *
 * VIPSupport participates as a Leaf in the Composite pattern and Observer participant.
 */
class VIPSupport : public EventUnit {
    public:
        /** @brief Constructs this VIPSupport. */
        VIPSupport();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onEvacuate() override;

};

#endif
