//
// Created by xxxx on 15.06.2022.
//

#include "SeaHorse.h"

CreatureType SeaHorse::getCreatureType() const {
    return WATER;
}

SeaHorse::SeaHorse() : Creature(18, 30, 50, 3, 0, 150, "SeaHorse") {}

std::string SeaHorse::getCreatureTypeString() const {
    return "WATER";
}

bool SeaHorse::specialAction(Creature *opponent) {
    if(specialPower > 0){
        specialPower--;


        if(actualHitPoints >= 11) {
            strength += 6;
            dexterity += 10;
            if (dexterity >= 95)
                dexterity = 95;
            actualHitPoints -= 10;
            if (actualHitPoints <= 0)
                actualHitPoints = 1;
            maxHitPoints -= 10;
        }

        attack(opponent);

        return true;
    }
    return false;
}