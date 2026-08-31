#include "RefereeTeam.h"
#include "EventNotice.h"
#include <iostream>

RefereeTeam::RefereeTeam() : EventUnit("Referee Team", 12) {}

void RefereeTeam::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void RefereeTeam::onServerOutage() {
    std::cout << "  Referee Team: suspends the current match and records its status." << std::endl;
}

void RefereeTeam::onScheduleChange() {
    std::cout << "  Referee Team: updates its match schedule." << std::endl;
}
