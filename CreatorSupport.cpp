#include "CreatorSupport.h"
#include "EventNotice.h"
#include <iostream>

CreatorSupport::CreatorSupport() : EventUnit("Creator Support", 30) {}

void CreatorSupport::update(const EventNotice& notice) {
    switch (notice.getType()) {
        case NoticeType::SCHEDULE_CHANGE:
            std::cout << "  Creator Support: updates content creators about schedule changes." << std::endl;
            break;
        default:
            std::cout << "  Creator Support: acknowledges " << notice.getTypeName() << "." << std::endl;
            break;
    }
}
