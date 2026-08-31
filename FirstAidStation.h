#ifndef FIRSTAIDSTATION_H
#define FIRSTAIDSTATION_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named FirstAidStation.
 *
 * FirstAidStation participates as a Leaf in the Composite pattern and Observer participant.
 */
class FirstAidStation : public EventUnit {
    public:
        /** @brief Constructs this FirstAidStation. */
        FirstAidStation();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onSafetyAlert() override;
        void onEvacuate() override;

};

#endif
