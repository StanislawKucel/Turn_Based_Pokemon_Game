//
// Created by xxxx on 12.06.2022.
//

#include "Golem.h"

CreatureType Golem::getCreatureType() const {
    return STEEL;
}

Golem::Golem() : Creature(1, 0, 200, 2, 0, 65, "Golem") {}

std::string Golem::getCreatureTypeString() const {
    return "STEEL";
}

bool Golem::specialAction(Creature *opponent) {
    if (specialPower > 0) {
        specialPower--;

        double tempStrength = strength;


        if (actualHitPoints <= 100) {
            strength += actualHitPoints;
        } else
            strength += 99;
        attack(opponent);

        strength = tempStrength;


        return true;
    }
    return false;
}