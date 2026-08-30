#include "DemoZone.h"
#include "GameDemoBooth.h"

DemoZone::DemoZone() : EventGroup("Demo Zone") {
    add(new GameDemoBooth());
}
