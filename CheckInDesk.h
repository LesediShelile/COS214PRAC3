#ifndef CHECKINDESK_H
#define CHECKINDESK_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named CheckInDesk.
 *
 * CheckInDesk participates as a Leaf in the Composite pattern and Observer participant.
 */
class CheckInDesk : public EventUnit {
    public:
        /** @brief Constructs this CheckInDesk. */
        CheckInDesk();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onCapacityAlert() override;

};

#endif
