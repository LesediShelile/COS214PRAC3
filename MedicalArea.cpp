#include "MedicalArea.h"
#include "FirstAidStation.h"
#include "MedicalTeam.h"

MedicalArea::MedicalArea() : EventGroup("Medical Services") {
    add(new FirstAidStation());
    add(new MedicalTeam());
}
