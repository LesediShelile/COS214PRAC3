#include "RegistrationArea.h"
#include "CheckInDesk.h"
#include "BadgeStation.h"
#include "InformationDesk.h"

// Encapsulated Composite: RegistrationArea knows what it contains; nothing
// outside this file needs to.
RegistrationArea::RegistrationArea() : EventGroup("Registration Centre") {
    add(new CheckInDesk());
    add(new BadgeStation());
    add(new InformationDesk());
}
