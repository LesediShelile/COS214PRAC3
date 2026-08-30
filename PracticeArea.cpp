#include "PracticeArea.h"
#include "GamingStation.h"
#include "TechnicalSupport.h"

PracticeArea::PracticeArea() : EventGroup("Practice Area") {
    add(new GamingStation());
    add(new TechnicalSupport());
}
