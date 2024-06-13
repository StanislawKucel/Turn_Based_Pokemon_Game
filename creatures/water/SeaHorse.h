//
// Created by xxxx on 15.06.2022.
//

#ifndef UNTITLED1_SEAHORSE_H
#define UNTITLED1_SEAHORSE_H


#include "../Creature.h"

class SeaHorse: public Creature {

public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    SeaHorse();
    bool specialAction(Creature* opponent);
};


#endif //UNTITLED1_SEAHORSE_H
