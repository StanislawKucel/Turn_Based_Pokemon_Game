//
// Created by xxxx on 05.06.2022.
//

#include "Rat.h"

CreatureType Rat::getCreatureType() const {
    return EARTH;
}

Rat::Rat() : Creature(8, 60, 25, 3, 0, 60, "Rat") {}

std::string Rat::getCreatureTypeString() const {
    return "EARTH";
}

bool Rat::specialAction(Creature *opponent) {
    if(specialPower > 0){
        specialPower--;
        double tempStrength = strength;
        strength *= 3;
        attack(opponent);
        strength = tempStrength;
        return true;
    }
    return false;
}
