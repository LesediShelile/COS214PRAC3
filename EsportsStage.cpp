#include "EsportsStage.h"
#include "EventNotice.h"
#include <iostream>

EsportsStage::EsportsStage() : EventUnit("Esports Stage", 200) {}

void EsportsStage::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::WEATHER_ALERT:
            close(); std::cout << "  Esports Stage: pauses outdoor matches for the weather alert." << std::endl; break;
        case NoticeType::SERVER_OUTAGE:
            std::cout << "  Esports Stage: pauses the match and saves the current score." << std::endl; break;
        case NoticeType::EVACUATE:
            close(); std::cout << "  Esports Stage: stops the tournament and clears the playing area." << std::endl; break;
        case NoticeType::RESUME:
            open(); std::cout << "  Esports Stage: resumes matches." << std::endl; break;
        default: std::cout << "  Esports Stage: acknowledges " << notice.getTypeName() << "." << std::endl; break;
    }
}
