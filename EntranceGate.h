#ifndef ENTRANCEGATE_H
#define ENTRANCEGATE_H

#include "EventUnit.h"

class EntranceGate : public EventUnit {
    public:
        EntranceGate();
        void update(const EventNotice& notice) override;
        void onEvacuate() override;

};

#endif
