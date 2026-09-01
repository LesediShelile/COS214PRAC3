#include "CreatorSupport.h"
#include "EventNotice.h"
#include <iostream>

CreatorSupport::CreatorSupport() : EventUnit("Creator Support", 30) {}

void CreatorSupport::update(const EventNotice& notice) {
    notice.dispatch(*this);
}
