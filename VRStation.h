#ifndef VRSTATION_H
#define VRSTATION_H

#include "EventUnit.h"

/** @brief Gaming-convention leaf responsible for VR Station. */
class VRStation : public EventUnit {
public:
    /** @brief Constructs the VR Station. */
    VRStation();
    /** @brief Applies this unit's polymorphic response to a notice. @param notice Notice received. */
    void update(const EventNotice& notice) override;
};

#endif
