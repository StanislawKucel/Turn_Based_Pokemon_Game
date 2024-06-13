//
// Created by xxxx on 05.06.2022.
//

#include "Snowman.h"

CreatureType Snowman::getCreatureType() const {
    return ICE;
}

Snowman::Snowman() : Creature(10, 0, 95, 4, 0, 140,
                              "Snowman") {}

std::string Snowman::getCreatureTypeString() const {
    return "ICE";
}

bool Snowman::specialAction(Creature *opponent) {
    if (specialPower > 0) {
        specialPower--;

        if (actualHitPoints >= 16) {
            double tempStrength = strength;
            attack(opponent);
            strength -= 2;
            if(strength < 0){
                strength =1;
            }
            attack(opponent);
            strength -= 2;
            if(strength < 0){
                strength =1;
            }
            attack(opponent);
            strength -= 2;
            if(strength < 0){
                strength =1;
            }
            attack(opponent);
            strength -= 2;
            if(strength < 0){
                strength =1;
            }
            attack(opponent);
            actualHitPoints -= 15;
            strength = tempStrength;
        } else {
            attack(opponent);
        }
        return true;
    }
    return false;
}