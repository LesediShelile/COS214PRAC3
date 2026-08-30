#include "ChampionshipArena.h"
#include "EsportsStage.h"
#include "RefereeTeam.h"
#include "SpectatorGate.h"

ChampionshipArena::ChampionshipArena() : EventGroup("Championship Arena") {
    add(new EsportsStage());
    add(new RefereeTeam());
    add(new SpectatorGate());
}
