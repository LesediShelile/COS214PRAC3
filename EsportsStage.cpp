#include "EsportsStage.h"
#include "EventNotice.h"
#include <iostream>

EsportsStage::EsportsStage() : EventUnit("Esports Stage", 800) {}

void EsportsStage::update(const EventNotice& notice) {
    // Safety alerts are scaled by severity: only a HIGH severity alert is
    // serious enough to pause a live match immediately. Lower severities
    // fall through to the default (lighter) onSafetyAlert() response.
    if (notice.getType() == "SAFETY_ALERT" &&
        notice.getSeverity() == EventNotice::Severity::HIGH) {
        std::cout << "  Esports Stage: HIGH severity safety alert - match paused immediately."
                   << std::endl;
        return;
    }
    notice.dispatch(*this);
}

void EsportsStage::onSafetyAlert() {
    std::cout << "  Esports Stage: safety alert noted, match continues under caution." << std::endl;
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
