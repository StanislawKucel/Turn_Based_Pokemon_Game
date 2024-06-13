//
// Created by xxxx on 05.06.2022.
//

#include "CreatureFactory.h"


const std::vector<std::string> CreatureFactory::creaturesNames = {
        "Rat",
        "Snowman",
        "Golem",
        "MagmaMan",
        "Ghost",
        "AirElemental",
        "Fairy",
        "NinjaSnail",
        "Mimic",
        "Dragon",
        "FireDog",
        "IceBird",
        "Yeti",
        "JakeLake",
        "BladeSinger",
        "GiantWave",
        "SeaHorse",
        "WaterDevil"
};

const std::vector<std::string> CreatureFactory::creaturesTypes = {
        "EARTH",
        "ICE",
        "STEEL",
        "FIRE",
        "AIR",
        "AIR",
        "AIR",
        "EARTH",
        "EARTH",
        "FIRE",
        "FIRE",
        "ICE",
        "ICE",
        "STEEL",
        "STEEL",
        "WATER",
        "WATER",
        "WATER"
};

Creature* CreatureFactory::createCreature(std::string creatureName) {
    if (creatureName == "Rat") {
        return new Rat();
    } else if (creatureName == "Snowman") {
        return new Snowman();
    }else if(creatureName == "Golem"){
        return new Golem();
    }else if(creatureName == "MagmaMan"){
        return new MagmaMan();
    }else if(creatureName == "Ghost"){
        return new Ghost();
    }else if(creatureName == "AirElemental"){
        return new AirElemental();
    }else if(creatureName == "Fairy"){
        return new Fairy();
    }else if(creatureName == "NinjaSnail"){
        return new NinjaSnail();
    }else if(creatureName == "Mimic"){
        return new Mimic();
    }else if(creatureName == "Dragon"){
        return new Dragon();
    }else if(creatureName == "FireDog"){
        return new FireDog();
    }else if(creatureName == "IceBird"){
        return new IceBird();
    }else if(creatureName == "Yeti"){
        return new Yeti();
    }else if(creatureName == "JakeLake"){
        return new JakeLake();
    }else if(creatureName == "BladeSinger"){
        return new BladeSinger();
    }else if(creatureName == "GiantWave"){
        return new GiantWave();
    }else if(creatureName == "SeaHorse"){
        return new SeaHorse();
    }else if(creatureName == "WaterDevil"){
        return new WaterDevil();
    } else {
        return nullptr;
    }
}

std::string CreatureFactory::getCreaturesInfo() {
    std::string info = "";
    for (int i = 0; i < creaturesNames.size(); ++i) {
        info += std::to_string(i+1) + " - " + creaturesNames[i] + " (" +creaturesTypes[i] + ")\n";
    }
    return info;
}
