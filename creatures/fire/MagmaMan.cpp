//
// Created by xxxx on 15.06.2022.
//

#include "MagmaMan.h"

CreatureType MagmaMan::getCreatureType() const {
    return FIRE;
}

MagmaMan::MagmaMan() : Creature(3, 10, 120, 10, 0, 85, "MagmaMan") {}

std::string MagmaMan::getCreatureTypeString() const {
    return "FIRE";
}

bool MagmaMan::specialAction(Creature *opponent) {
    if (specialPower > 0) {
        specialPower--;

        if (actualHitPoints >= 16) {
            strength *= 2;
            maxHitPoints -= 15;
            if (actualHitPoints > maxHitPoints)
                actualHitPoints = maxHitPoints;
        } else {
            maxHitPoints += 20;
            actualHitPoints += 20;

        }


        return true;
    }
    return false;
}