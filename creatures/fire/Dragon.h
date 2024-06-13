//
// Created by xxxx on 15.06.2022.
//

#ifndef UNTITLED1_DRAGON_H
#define UNTITLED1_DRAGON_H


#include "../Creature.h"

class Dragon: public Creature{
public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    Dragon();
    bool specialAction(Creature* opponent);
};


#endif //UNTITLED1_DRAGON_H
