//
// Created by xxxx on 15.06.2022.
//

#include "NinjaSnail.h"

CreatureType NinjaSnail::getCreatureType() const {
    return EARTH;
}

NinjaSnail::NinjaSnail() : Creature(3, 90, 15, 2, 0, 85, "NinjaSnail") {}

std::string NinjaSnail::getCreatureTypeString() const {
    return "EARTH";
}

bool NinjaSnail::specialAction(Creature *opponent) {
    if(specialPower > 0){
        specialPower--;
        double tempStrength = strength;

        dexterity -= 10;
        if(dexterity <= 0){
            dexterity = 0;
        }
        strength *= 2;
        attack(opponent);
        strength /= 2;
        attack(opponent);
        attack(opponent);
        strength *= 3;
        attack(opponent);
        strength = tempStrength;
        return true;
    }
    return false;
}