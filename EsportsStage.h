#ifndef ESPORTSSTAGE_H
#define ESPORTSSTAGE_H

#include "EventUnit.h"

class EsportsStage : public EventUnit {
    public:
        EsportsStage();
        void update(const EventNotice& notice) override;
};

#endif
