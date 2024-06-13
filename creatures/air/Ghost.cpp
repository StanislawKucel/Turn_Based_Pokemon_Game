//
// Created by xxxx on 15.06.2022.
//

#include "Ghost.h"

CreatureType Ghost::getCreatureType() const {
    return AIR;
}

Ghost::Ghost() : Creature(2, 95, 1, 99, 0, 100, "Ghost") {}

std::string Ghost::getCreatureTypeString() const {
    return "AIR";
}

bool Ghost::specialAction(Creature *opponent) {
    if(specialPower > 0){
        specialPower--;
        strength += 5;

        dexterity -= 7;
        if(dexterity <= 0){
            dexterity = 0;
            strength +=3;
        }
        double tempStrength = strength;
        strength /= 2;
        attack(opponent);
        strength = tempStrength;

        return true;
    }
    return false;
}