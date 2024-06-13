//
// Created by xxxx on 15.06.2022.
//

#include "WaterDevil.h"

CreatureType WaterDevil::getCreatureType() const {
    return WATER;
}

WaterDevil::WaterDevil() : Creature(35, 0, 150, 2, 0, 200, "WaterDevil") {}

std::string WaterDevil::getCreatureTypeString() const {
    return "WATER";
}

bool WaterDevil::specialAction(Creature *opponent) {
    if (specialPower > 0) {
        specialPower--;

        if (actualHitPoints == maxHitPoints) {
            attack(opponent);
            attack(opponent);
            attack(opponent);
            attack(opponent);
            attack(opponent);
            maxHitPoints -= (rand() % (91)) + 10;
            if (maxHitPoints <= 0)
                maxHitPoints = 1;

            if (actualHitPoints > maxHitPoints)
                actualHitPoints = maxHitPoints;
        } else if (actualHitPoints >= 100) {
            attack(opponent);
            attack(opponent);
            attack(opponent);
            attack(opponent);
            maxHitPoints -= (rand() % (91)) + 10;
            if (maxHitPoints <= 0)
                maxHitPoints = 1;

            if (actualHitPoints > maxHitPoints)
                actualHitPoints = maxHitPoints;
        } else if (actualHitPoints >= 50) {
            attack(opponent);
            attack(opponent);
        } else {
            attack(opponent);
            attack(opponent);
            double tempHp = (rand() % (91)) + 10;
            maxHitPoints += tempHp;
            actualHitPoints += tempHp;
        }

        return true;
    }
    return false;
}