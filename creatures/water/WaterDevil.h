//
// Created by xxxx on 15.06.2022.
//

#ifndef UNTITLED1_WATERDEVIL_H
#define UNTITLED1_WATERDEVIL_H

#include "../Creature.h"

class WaterDevil: public Creature {

public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    WaterDevil();
    bool specialAction(Creature* opponent);
};


#endif //UNTITLED1_WATERDEVIL_H
