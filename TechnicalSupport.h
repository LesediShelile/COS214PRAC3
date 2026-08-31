#ifndef TECHNICALSUPPORT_H
#define TECHNICALSUPPORT_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named TechnicalSupport.
 *
 * TechnicalSupport participates as a Leaf in the Composite pattern and Observer participant.
 */
class TechnicalSupport : public EventUnit {
    public:
        /** @brief Constructs this TechnicalSupport. */
        TechnicalSupport();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onServerOutage() override;

};

#endif
