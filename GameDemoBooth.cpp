#include "GameDemoBooth.h"
#include "EventNotice.h"
#include <iostream>

GameDemoBooth::GameDemoBooth() : EventUnit("Game Demo Booth", 60) {}

void GameDemoBooth::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void GameDemoBooth::onScheduleChange() {
    std::cout << "  Game Demo Booth: updates its demonstration timetable." << std::endl;
}
