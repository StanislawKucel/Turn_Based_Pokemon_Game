//
// Created by xxxx on 15.06.2022.
//

#include "GiantWave.h"

CreatureType GiantWave::getCreatureType() const {
    return WATER;
}

GiantWave::GiantWave() : Creature(15, 5, 300, 0, 0, 240, "GiantWave") {}

std::string GiantWave::getCreatureTypeString() const {
    return "WATER";
}

bool GiantWave::specialAction(Creature *opponent) {
    return false;
}