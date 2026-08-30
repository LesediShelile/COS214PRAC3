#include "RefereeTeam.h"
#include "EventNotice.h"
#include <iostream>

RefereeTeam::RefereeTeam() : EventUnit("Referee Team") {}

void RefereeTeam::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::SERVER_OUTAGE:
            std::cout << "  Referee Team: suspends the current match and records its status." << std::endl;
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "  Referee Team: updates its match schedule." << std::endl;
            break;
        default:
            std::cout << "  Referee Team: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
