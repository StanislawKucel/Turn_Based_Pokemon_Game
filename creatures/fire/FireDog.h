//
// Created by xxxx on 15.06.2022.
//

#ifndef UNTITLED1_FIREDOG_H
#define UNTITLED1_FIREDOG_H


#include "../Creature.h"

class FireDog: public Creature{
public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    FireDog();
    bool specialAction(Creature* opponent);
};

#endif //UNTITLED1_FIREDOG_H
