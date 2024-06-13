//
// Created by xxxx on 15.06.2022.
//

#ifndef UNTITLED1_YETI_H
#define UNTITLED1_YETI_H


#include "../Creature.h"

class Yeti: public Creature{
public:
    CreatureType getCreatureType() const;
    std::string getCreatureTypeString() const;

    Yeti();
    bool specialAction(Creature* opponent);
};;


#endif //UNTITLED1_YETI_H
