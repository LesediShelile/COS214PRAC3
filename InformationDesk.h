#ifndef INFORMATIONDESK_H
#define INFORMATIONDESK_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named InformationDesk.
 *
 * InformationDesk participates as a Leaf in the Composite pattern and Observer participant.
 */
class InformationDesk : public EventUnit {
    public:
        /** @brief Constructs this InformationDesk. */
        InformationDesk();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onServerOutage() override;
        void onScheduleChange() override;

};

#endif
