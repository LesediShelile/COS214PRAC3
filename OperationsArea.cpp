#include "OperationsArea.h"
#include "RegistrationArea.h"
#include "SecurityArea.h"
#include "MedicalArea.h"

OperationsArea::OperationsArea() : EventGroup("Main Operations") {
    add(new RegistrationArea());
    add(new SecurityArea());
    add(new MedicalArea());
}
