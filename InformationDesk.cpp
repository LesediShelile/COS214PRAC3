#include "InformationDesk.h"
#include "EventNotice.h"
#include <iostream>

InformationDesk::InformationDesk()
    : EventUnit("Information Desk", 80) {}

void InformationDesk::update(const EventNotice& notice) {
    std::cout << "  Information Desk: keeps attendees informed about event changes."
              << std::endl;
}