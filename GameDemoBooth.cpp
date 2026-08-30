#include "GameDemoBooth.h"
#include "EventNotice.h"
#include <iostream>

GameDemoBooth::GameDemoBooth() : EventUnit("Game Demo Booth", 40) {}

void GameDemoBooth::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "  Game Demo Booth: updates its demo timetable." << std::endl; break;
        case NoticeType::SERVER_OUTAGE:
            std::cout << "  Game Demo Booth: switches to offline demos." << std::endl; break;
        case NoticeType::EVACUATE:
            close(); std::cout << "  Game Demo Booth: shuts down demo equipment safely." << std::endl; break;
        default: std::cout << "  Game Demo Booth: acknowledges " << notice.getTypeName() << "." << std::endl; break;
    }
}
