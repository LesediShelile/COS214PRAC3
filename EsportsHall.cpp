#include "EsportsHall.h"
#include "ChampionshipArena.h"
#include "PracticeArea.h"

EsportsHall::EsportsHall() : EventGroup("Esports Hall") {
    add(new ChampionshipArena());
    add(new PracticeArea());
}
