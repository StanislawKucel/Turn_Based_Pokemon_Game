//
// Created by xxxx on 15.06.2022.
//

#ifndef UNTITLED1_FAIRY_H
#define UNTITLED1_FAIRY_H


#include "../Creature.h"

class Fairy: public Creature {

public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    Fairy();

    bool specialAction(Creature* opponent);
};

#endif //UNTITLED1_FAIRY_H
