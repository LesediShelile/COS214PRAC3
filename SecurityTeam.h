#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include "EventUnit.h"

/**
 * @brief Concrete EventUnit named SecurityTeam.
 *
 * SecurityTeam participates as a Leaf in the Composite pattern and Observer participant.
 */
class SecurityTeam : public EventUnit {
    public:
        /** @brief Constructs this SecurityTeam. */
        SecurityTeam();
        /** @brief Reacts to a pushed event notice. @param notice Notice received from a Subject. */
        void update(const EventNotice& notice) override;
        void onSafetyAlert() override;
        void onEvacuate() override;

};

#endif
