#ifndef FIRSTAIDSTATION_H
#define FIRSTAIDSTATION_H

#include "EventUnit.h"

class FirstAidStation : public EventUnit {
    public:
        FirstAidStation();
        void update(const EventNotice& notice) override;
};

#endif
