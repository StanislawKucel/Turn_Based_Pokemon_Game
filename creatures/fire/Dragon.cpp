//
// Created by xxxx on 15.06.2022.
//

#include "Dragon.h"

CreatureType Dragon::getCreatureType() const{
    return FIRE;
}

Dragon::Dragon() : Creature(35, 0, 85, 1, 0, 200,"Dragon") {}

std::string Dragon::getCreatureTypeString() const {
    return "FIRE";
}

bool Dragon::specialAction(Creature *opponent) {
    if(specialPower > 0){
        specialPower--;
        double tempStrength = strength;

        if (actualHitPoints >= 41) {
            strength += 10;
            attack(opponent);
            attack(opponent);
            attack(opponent);
            attack(opponent);
            actualHitPoints -= 40;
            strength = tempStrength;
            dexterity += 20;
            if(dexterity >= 95){
                dexterity = 95;
            }
        }
        else {
            maxHitPoints += 75;
            actualHitPoints += 75;
        }
        return true;
    }
    return false;
}