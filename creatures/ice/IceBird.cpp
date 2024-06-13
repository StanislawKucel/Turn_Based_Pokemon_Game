//
// Created by xxxx on 15.06.2022.
//

#include "IceBird.h"

CreatureType IceBird::getCreatureType() const {
    return ICE;
}

IceBird::IceBird() : Creature(30, 50, 5, 2, 0, 65, "IceBird") {}

std::string IceBird::getCreatureTypeString() const {
    return "ICE";
}

bool IceBird::specialAction(Creature *opponent) {
    if (specialPower > 0) {
        specialPower--;

        maxHitPoints += 10;
        actualHitPoints += 10;
        attack(opponent);

        return true;
    }
    return false;
}