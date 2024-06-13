//
// Created by xxxx on 15.06.2022.
//

#include "Fairy.h"

CreatureType Fairy::getCreatureType() const {
    return AIR;
}

Fairy::Fairy() : Creature(12, 50, 25, 2, 0, 85, "Fairy") {}

std::string Fairy::getCreatureTypeString() const {
    return "AIR";
}

bool Fairy::specialAction(Creature *opponent) {
    if(specialPower > 0){
        specialPower--;

        attack(opponent);
        attack(opponent);
        attack(opponent);



        return true;
    }
    return false;
}