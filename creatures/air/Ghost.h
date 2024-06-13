//
// Created by xxxx on 15.06.2022.
//

#ifndef UNTITLED1_GHOST_H
#define UNTITLED1_GHOST_H


#include "../Creature.h"

class Ghost: public Creature {

public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    Ghost();

    bool specialAction(Creature* opponent);
};


#endif //UNTITLED1_GHOST_H
