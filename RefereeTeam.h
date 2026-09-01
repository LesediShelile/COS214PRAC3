#ifndef REFEREETEAM_H
#define REFEREETEAM_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named RefereeTeam.
 *
 * RefereeTeam participates as a Leaf in the Composite pattern and Observer participant.
 */
class RefereeTeam : public EventUnit {
    public:
        /** @brief Constructs this RefereeTeam. */
        RefereeTeam();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onServerOutage() override;
        void onScheduleChange() override;

};

#endif
