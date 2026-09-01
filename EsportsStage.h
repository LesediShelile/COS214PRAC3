#ifndef ESPORTSSTAGE_H
#define ESPORTSSTAGE_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named EsportsStage.
 *
 * EsportsStage participates as a Leaf in the Composite pattern and Observer participant.
 */
class EsportsStage : public EventUnit {
    public:
        /** @brief Constructs this EsportsStage. */
        EsportsStage();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onSafetyAlert() override;
        void onServerOutage() override;
        void onEvacuate() override;
        void onScheduleChange() override;

};

#endif
