//
// Created by xxxx on 15.06.2022.
//

#include "BladeSinger.h"

CreatureType BladeSinger::getCreatureType() const {
    return STEEL;
}

BladeSinger::BladeSinger() : Creature(18, 85, 10, 4, 0, 130, "BladeSinger") , specialActionCounter(0){}

std::string BladeSinger::getCreatureTypeString() const {
    return "STEEL";
}

bool BladeSinger::specialAction(Creature *opponent) {
    if(specialPower > 0){
        specialPower--;
        specialActionCounter++;

        strength += specialActionCounter * 2;
        dexterity -= specialActionCounter * 2;
        if(dexterity < 0){
            dexterity = 0;
        }

        return true;
    }
    return false;
}