#include "EsportsStage.h"
#include "EventNotice.h"
#include <iostream>

EsportsStage::EsportsStage() : EventUnit("Esports Stage", 800) {}

void EsportsStage::update(const EventNotice& notice) {
    notice.dispatch(*this);
}

void EsportsStage::onSafetyAlert() {
    std::cout << "  Esports Stage: pauses the current tournament match." << std::endl;
}

void EsportsStage::onServerOutage() {
    std::cout << "  Esports Stage: pauses the tournament." << std::endl;
}

void EsportsStage::onEvacuate() {
    std::cout << "  Esports Stage: immediately pauses the tournament." << std::endl;
}

void EsportsStage::onScheduleChange() {
    std::cout << "  Esports Stage: updates the tournament start time." << std::endl;
}
