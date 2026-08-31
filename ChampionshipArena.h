#ifndef CHAMPIONSHIPARENA_H
#define CHAMPIONSHIPARENA_H

#include "EventGroup.h"

/**
 * @brief Concrete EventGroup named ChampionshipArena.
 *
 * ChampionshipArena participates as a Composite node in the GameVerse ownership tree.
 */
class ChampionshipArena : public EventGroup {
    public:
        /** @brief Constructs this ChampionshipArena. */
        ChampionshipArena();
};

#endif
