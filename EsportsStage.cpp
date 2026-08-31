#include "EsportsStage.h"
#include "EventNotice.h"
#include <iostream>

EsportsStage::EsportsStage()
    : EventUnit("Esports Stage", 800) {}

void EsportsStage::update(const EventNotice& notice) {
    std::cout << "  Esports Stage: pauses the tournament and secures the stage."
              << std::endl;
}