#include "CreatorSupport.h"
#include "EventNotice.h"
#include <iostream>

CreatorSupport::CreatorSupport()
    : EventUnit("Creator Support", 30) {}

void CreatorSupport::update(const EventNotice& notice) {
    std::cout << "  Creator Support: updates content creators about "
              << notice.getType() << "." << std::endl;
}