#include "Convention.h"
#include "OperationsArea.h"
#include "EsportsHall.h"
#include "ExperienceHall.h"
#include "VIPCreatorLounge.h"

// Convention encapsulates the whole tree: the Client only ever needs to
// know that a Convention exists, not what it's built from.
Convention::Convention() : EventGroup("GameVerse Convention") {
    add(new OperationsArea());
    add(new EsportsHall());
    add(new ExperienceHall());
    add(new VIPCreatorLounge());
}
