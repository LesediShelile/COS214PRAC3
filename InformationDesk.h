#ifndef INFORMATIONDESK_H
#define INFORMATIONDESK_H

#include "EventUnit.h"

/** @brief Gaming-convention leaf responsible for Information Desk. */
class InformationDesk : public EventUnit {
public:
    /** @brief Constructs the Information Desk. */
    InformationDesk();
    /** @brief Applies this unit's polymorphic response to a notice. @param notice Notice received. */
    void update(const EventNotice& notice) override;
};

#endif
