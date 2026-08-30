#include "EsportsStage.h"
#include "EventNotice.h"
#include <iostream>

EsportsStage::EsportsStage() : EventUnit("Esports Stage", 800) {}

void EsportsStage::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::SAFETY_ALERT:
            std::cout << "  Esports Stage: pauses the current tournament match." << std::endl;
            break;
        case NoticeType::SERVER_OUTAGE:
            std::cout << "  Esports Stage: pauses the tournament." << std::endl;
            break;
        case NoticeType::EVACUATE:
            std::cout << "  Esports Stage: immediately pauses the tournament." << std::endl;
            break;
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "  Esports Stage: updates the tournament start time." << std::endl;
            break;
        default:
            std::cout << "  Esports Stage: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
