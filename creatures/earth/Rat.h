//
// Created by xxxx on 05.06.2022.
//

#ifndef UNTITLED1_RAT_H
#define UNTITLED1_RAT_H

#include "../Creature.h"

class Rat: public Creature {

public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    Rat();

    bool specialAction(Creature* opponent);
};


#endif //UNTITLED1_RAT_H
