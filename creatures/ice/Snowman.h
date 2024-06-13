//
// Created by xxxx on 05.06.2022.
//

#ifndef UNTITLED1_SNOWMAN_H
#define UNTITLED1_SNOWMAN_H

#include "../Creature.h"

class Snowman: public Creature{
public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    Snowman();
    bool specialAction(Creature* opponent);
};


#endif //UNTITLED1_SNOWMAN_H
