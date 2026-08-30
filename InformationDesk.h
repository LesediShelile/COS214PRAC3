#ifndef INFORMATIONDESK_H
#define INFORMATIONDESK_H

#include "EventUnit.h"

class InformationDesk : public EventUnit {
    public:
        InformationDesk();
        void update(const EventNotice& notice) override;
};

#endif
