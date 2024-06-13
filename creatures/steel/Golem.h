//
// Created by xxxx on 12.06.2022.
//

#ifndef UNTITLED1_GOLEM_H
#define UNTITLED1_GOLEM_H


#include "../Creature.h"

class Golem: public Creature {

public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    Golem();
    bool specialAction(Creature* opponent);
};


#endif //UNTITLED1_GOLEM_H
