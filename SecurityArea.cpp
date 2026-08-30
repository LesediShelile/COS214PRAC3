#include "SecurityArea.h"
#include "SecurityStation.h"
#include "EntranceGate.h"
#include "SecurityTeam.h"

SecurityArea::SecurityArea() : EventGroup("Security Operations") {
    add(new SecurityStation());
    add(new EntranceGate());
    add(new SecurityTeam());
}
