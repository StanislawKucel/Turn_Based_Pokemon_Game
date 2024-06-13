//
// Created by xxxx on 15.06.2022.
//

#ifndef UNTITLED1_NINJASNAIL_H
#define UNTITLED1_NINJASNAIL_H


#include "../Creature.h"

class NinjaSnail: public Creature {

public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    NinjaSnail();
    bool specialAction(Creature* opponent);
};

#endif //UNTITLED1_NINJASNAIL_H
