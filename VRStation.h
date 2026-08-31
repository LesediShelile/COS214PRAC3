#ifndef VRSTATION_H
#define VRSTATION_H

#include "EventUnit.h"

class VRStation : public EventUnit {
    public:
        VRStation();
        void update(const EventNotice& notice) override;
        void onCapacityAlert() override;
        void onEvacuate() override;

};

#endif
