//
// Created by xxxx on 15.06.2022.
//

#ifndef UNTITLED1_MIMIC_H
#define UNTITLED1_MIMIC_H


#include "../Creature.h"

class Mimic: public Creature {

public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    Mimic();
    bool specialAction(Creature* opponent);
};

#endif //UNTITLED1_MIMIC_H
