//
// Created by xxxx on 15.06.2022.
//

#include "JakeLake.h"

CreatureType JakeLake::getCreatureType() const {
    return STEEL;
}

JakeLake::JakeLake() : Creature(6, 75, 25, 3, 0, 110, "JakeLake") {}

std::string JakeLake::getCreatureTypeString() const {
    return "STEEL";
}

bool JakeLake::specialAction(Creature *opponent) {
    if(specialPower > 0){
        specialPower--;

        dexterity += 5;
        if(dexterity >= 95){
            dexterity = 95;
        }

        attack(opponent);
        attack(opponent);


        return true;
    }
    return false;
}