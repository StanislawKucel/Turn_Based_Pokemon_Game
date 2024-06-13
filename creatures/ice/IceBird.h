//
// Created by xxxx on 15.06.2022.
//

#ifndef UNTITLED1_ICEBIRD_H
#define UNTITLED1_ICEBIRD_H

#include "../Creature.h"

class IceBird: public Creature{
public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    IceBird();
    bool specialAction(Creature* opponent);
};


#endif //UNTITLED1_ICEBIRD_H
