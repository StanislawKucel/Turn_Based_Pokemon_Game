//
// Created by xxxx on 15.06.2022.
//

#ifndef UNTITLED1_BLADESINGER_H
#define UNTITLED1_BLADESINGER_H


#include "../Creature.h"

class BladeSinger: public Creature {
private:
    int specialActionCounter;

public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    BladeSinger();
    bool specialAction(Creature* opponent);
};

#endif //UNTITLED1_BLADESINGER_H
