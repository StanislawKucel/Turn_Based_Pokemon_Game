//
// Created by xxxx on 15.06.2022.
//

#include "Mimic.h"

CreatureType Mimic::getCreatureType() const {
    return EARTH;
}

Mimic::Mimic() : Creature(15, 10, 50, 4, 0, 100, "Mimic") {}

std::string Mimic::getCreatureTypeString() const {
    return "EARTH";
}

bool Mimic::specialAction(Creature *opponent) {
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