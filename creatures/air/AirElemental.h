//
// Created by xxxx on 15.06.2022.
//

#ifndef UNTITLED1_AIRELEMENTAL_H
#define UNTITLED1_AIRELEMENTAL_H


#include "../Creature.h"

class AirElemental: public Creature {

public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    AirElemental();

    bool specialAction(Creature* opponent);
};

#endif //UNTITLED1_AIRELEMENTAL_H
