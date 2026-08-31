#ifndef VIPCHECKIN_H
#define VIPCHECKIN_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named VIPCheckIn.
 *
 * VIPCheckIn participates as a Leaf in the Composite pattern and Observer participant.
 */
class VIPCheckIn : public EventUnit {
    public:
        /** @brief Constructs this VIPCheckIn. */
        VIPCheckIn();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onSafetyAlert() override;
        void onEvacuate() override;
        void onScheduleChange() override;

};

#endif
