#ifndef SECURITYSTATION_H
#define SECURITYSTATION_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named SecurityStation.
 *
 * SecurityStation participates as a Leaf in the Composite pattern and Observer participant.
 */
class SecurityStation : public EventUnit {
    public:
        /** @brief Constructs this SecurityStation. */
        SecurityStation();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onCapacityAlert() override;

};

#endif
