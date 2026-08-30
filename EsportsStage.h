#ifndef ESPORTSSTAGE_H
#define ESPORTSSTAGE_H

#include "EventUnit.h"

/** @brief Gaming-convention leaf responsible for Esports Stage. */
class EsportsStage : public EventUnit {
public:
    /** @brief Constructs the Esports Stage. */
    EsportsStage();
    /** @brief Applies this unit's polymorphic response to a notice. @param notice Notice received. */
    void update(const EventNotice& notice) override;
};

#endif
