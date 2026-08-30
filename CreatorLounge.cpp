#include "CreatorLounge.h"
#include "CreatorSupport.h"
#include "MediaStation.h"

CreatorLounge::CreatorLounge() : EventGroup("Creator Area") {
    add(new CreatorSupport());
    add(new MediaStation());
}
