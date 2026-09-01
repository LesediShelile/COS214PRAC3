#ifndef VRSTATION_H
#define VRSTATION_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named VRStation.
 *
 * VRStation participates as a Leaf in the Composite pattern and Observer participant.
 */
class VRStation : public EventUnit {
    public:
        /** @brief Constructs this VRStation. */
        VRStation();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onCapacityAlert() override;
        void onEvacuate() override;

};

#endif
