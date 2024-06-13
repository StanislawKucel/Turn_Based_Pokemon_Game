//
// Created by xxxx on 15.06.2022.
//

#ifndef UNTITLED1_MAGMAMAN_H
#define UNTITLED1_MAGMAMAN_H


#include "../Creature.h"

class MagmaMan: public Creature {

public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    MagmaMan();
    bool specialAction(Creature* opponent);
};


#endif //UNTITLED1_MAGMAMAN_H
