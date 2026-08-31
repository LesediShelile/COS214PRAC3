#ifndef CREATORSUPPORT_H
#define CREATORSUPPORT_H

#include "EventUnit.h"

class CreatorSupport : public EventUnit {
    public:
        CreatorSupport();
        void update(const EventNotice& notice) override;

};

#endif
