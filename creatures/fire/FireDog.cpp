//
// Created by xxxx on 15.06.2022.
//

#include "FireDog.h"

CreatureType FireDog::getCreatureType() const{
    return FIRE;
}

FireDog::FireDog() : Creature(10, 40, 35, 2, 0, 75,"FireDog") {}

std::string FireDog::getCreatureTypeString() const {
    return "FIRE";
}

bool FireDog::specialAction(Creature *opponent) {
    if(specialPower > 0){
        specialPower--;

        strength += 4;
        dexterity += 4;
        if(dexterity >= 95){
            dexterity = 95;
        }
        attack(opponent);

        return true;
    }
    return false;
}