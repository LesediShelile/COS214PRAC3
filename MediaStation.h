#ifndef MEDIASTATION_H
#define MEDIASTATION_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named MediaStation.
 *
 * MediaStation participates as a Leaf in the Composite pattern and Observer participant.
 */
class MediaStation : public EventUnit {
    public:
        /** @brief Constructs this MediaStation. */
        MediaStation();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onServerOutage() override;

};

#endif
