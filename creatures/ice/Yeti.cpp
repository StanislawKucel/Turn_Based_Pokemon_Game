//
// Created by xxxx on 15.06.2022.
//

#include "Yeti.h"

CreatureType Yeti::getCreatureType() const{
    return ICE;
}

Yeti::Yeti() : Creature(20, 10, 85, 3, 0, 180, "Yeti") {}

std::string Yeti::getCreatureTypeString() const {
    return "ICE";
}

bool Yeti::specialAction(Creature *opponent) {
    if(specialPower > 0){
        specialPower--;
        double tempStrength = strength;
        strength *= 7;
        attack(opponent);
        strength = tempStrength;
        return true;
    }
    return false;
}