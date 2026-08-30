#ifndef SECURITYTEAM_H
#define SECURITYTEAM_H

#include "EventUnit.h"

/** @brief Gaming-convention leaf responsible for Security Team. */
class SecurityTeam : public EventUnit {
public:
    /** @brief Constructs the Security Team. */
    SecurityTeam();
    /** @brief Applies this unit's polymorphic response to a notice. @param notice Notice received. */
    void update(const EventNotice& notice) override;
};

#endif
