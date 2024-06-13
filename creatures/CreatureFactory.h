//
// Created by xxxx on 05.06.2022.
//

#ifndef UNTITLED1_CREATUREFACTORY_H
#define UNTITLED1_CREATUREFACTORY_H

#include <string>
#include <vector>
#include "Creature.h"
#include "CreatureName.h"
#include "Creature.h"
#include "earth/Rat.h"
#include "ice/Snowman.h"
#include "steel/Golem.h"
#include "fire/MagmaMan.h"
#include "air/Ghost.h"
#include "air/AirElemental.h"
#include "air/Fairy.h"
#include "earth/NinjaSnail.h"
#include "earth/Mimic.h"
#include "fire/Dragon.h"
#include "fire/FireDog.h"
#include "ice/IceBird.h"
#include "ice/Yeti.h"
#include "steel/JakeLake.h"
#include "steel/BladeSinger.h"
#include "water/GiantWave.h"
#include "water/SeaHorse.h"
#include "water/WaterDevil.h"

class CreatureFactory {
private:

public:
    static const std::vector<std::string> creaturesNames;
    static const std::vector<std::string> creaturesTypes;

    static Creature* createCreature(std::string creatureName);
    static std::string getCreaturesInfo();
};


#endif //UNTITLED1_CREATUREFACTORY_H
