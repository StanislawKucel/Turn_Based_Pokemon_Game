//
// Created by xxxx on 15.06.2022.
//

#ifndef UNTITLED1_GIANTWAVE_H
#define UNTITLED1_GIANTWAVE_H


#include "../Creature.h"

class GiantWave: public Creature {

public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    GiantWave();
    bool specialAction(Creature* opponent);
};

#endif //UNTITLED1_GIANTWAVE_H
