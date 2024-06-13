//
// Created by xxxx on 15.06.2022.
//

#include "AirElemental.h"

CreatureType AirElemental::getCreatureType() const {
    return AIR;
}

AirElemental::AirElemental() : Creature(8, 75, 15, 10, 0, 120, "AirElemental") {}

std::string AirElemental::getCreatureTypeString() const {
    return "AIR";
}

bool AirElemental::specialAction(Creature *opponent) {
    if(specialPower > 0){
        specialPower--;


       maxHitPoints = maxHitPoints + 8;
       actualHitPoints += 8;
       strength = strength+1;





        return true;
    }
    return false;
}