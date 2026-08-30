#include "GameDemoBooth.h"
#include "EventNotice.h"
#include <iostream>

GameDemoBooth::GameDemoBooth() : EventUnit("Game Demo Booth") {}

void GameDemoBooth::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "  Game Demo Booth: updates its demonstration timetable." << std::endl;
            break;
        default:
            std::cout << "  Game Demo Booth: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
