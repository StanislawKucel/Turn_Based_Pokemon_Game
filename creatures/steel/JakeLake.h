//
// Created by xxxx on 15.06.2022.
//

#ifndef UNTITLED1_JAKELAKE_H
#define UNTITLED1_JAKELAKE_H


#include "../Creature.h"

class JakeLake: public Creature {

public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    JakeLake();
    bool specialAction(Creature* opponent);
};


#endif //UNTITLED1_JAKELAKE_H
