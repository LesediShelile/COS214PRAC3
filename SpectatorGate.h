#ifndef SPECTATORGATE_H
#define SPECTATORGATE_H

#include "EventUnit.h"

class SpectatorGate : public EventUnit {
    public:
        SpectatorGate();
        void update(const EventNotice& notice) override;
};

#endif
