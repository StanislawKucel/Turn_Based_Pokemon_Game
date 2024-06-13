//
// Created by xxxx on 05.06.2022.
//

#include "Creature.h"
#include "../interaction/InteractionTable.h"
#include "../help/ConsoleHelper.h"

double Creature::getStrength() const {
    return strength;
}

double Creature::getDexterity() const {
    return dexterity;
}

int Creature::getSpecialPower() const {
    return specialPower;
}

double Creature::getExp() const {
    return exp;
}

double Creature::getExpBonus() const {
    return expBonus;
}

const std::string &Creature::getName() const {
    return name;
}

Creature::Creature(double strength, double dexterity, double hitPoints, int specialPower, double exp, double expBonus,
                   const std::string &name) : strength(strength), dexterity(dexterity),
                                              maxHitPoints(hitPoints), actualHitPoints(hitPoints),
                                              specialPower(specialPower),
                                              exp(exp), expBonus(expBonus), name(name), expWhenDied(expBonus) {}

bool Creature::isAlive() const {
    return actualHitPoints > 0.0;
}

void Creature::attack(Creature *opponent) {
    double help = rand() / (double) RAND_MAX * 100;
    if (help < dexterity) {
        //attack has been missed
        ConsoleHelper::printAttackHaveMissed();
        return;
    }
    double efficiency = InteractionTable::getAttackEfficiency(this, opponent);
    efficiency = 1.0 + efficiency / 100.0;
    opponent->actualHitPoints -= (strength * efficiency);
    if(!opponent->isAlive()){
        exp += opponent->expWhenDied;
        opponent->expWhenDied = 0;
    }
    ConsoleHelper::printAttackInformation(this,opponent);
}

bool Creature::evolution() {
    if (exp >= expBonus) {
        exp = 0.0;
        maxHitPoints *= 1.1;
        actualHitPoints += 0.5 * maxHitPoints;
        if (actualHitPoints > maxHitPoints) {
            actualHitPoints = maxHitPoints;
        }
        strength += 2;
        dexterity += 1;
        if (dexterity > 95) {
            dexterity = 95;
        }
        return true;
    }
    return false;
}

double Creature::getActualHitPoints() const {
    return actualHitPoints;
}

void Creature::saveToFile(std::ofstream &file){
    file << name << std::endl;
    file << strength << std::endl;
    file << dexterity << std::endl;
    file << maxHitPoints << std::endl;
    file << actualHitPoints << std::endl;
    file << specialPower << std::endl;
    file << exp << std::endl;
    file << expBonus << std::endl;
    file << expWhenDied ;


}

void Creature::setStrength(double strength) {
    Creature::strength = strength;
}

void Creature::setDexterity(double dexterity) {
    Creature::dexterity = dexterity;
}

void Creature::setMaxHitPoints(double maxHitPoints) {
    Creature::maxHitPoints = maxHitPoints;
}

void Creature::setActualHitPoints(double actualHitPoints) {
    Creature::actualHitPoints = actualHitPoints;
}

void Creature::setSpecialPower(int specialPower) {
    Creature::specialPower = specialPower;
}

void Creature::setExp(double exp) {
    Creature::exp = exp;
}

void Creature::setExpBonus(double expBonus) {
    Creature::expBonus = expBonus;
}

void Creature::setExpWhenDied(double expWhenDied) {
    Creature::expWhenDied = expWhenDied;
}

Creature *Creature::loadFromFile(std::ifstream &file) {
    int temp;
    std::string tempStr;
    double tempDouble;
    file >> tempStr;
    Creature *monster = CreatureFactory::createCreature(tempStr);
    file >> tempDouble;
    monster->setStrength(tempDouble);
    file >> tempDouble;
    monster->setDexterity(tempDouble);
    file >> tempDouble;
    monster->setMaxHitPoints(tempDouble);
    file >> tempDouble;
    monster->setActualHitPoints(tempDouble);
    file >> temp;
    monster->setSpecialPower(temp);
    file >> tempDouble;
    monster->setExp(tempDouble);
    file >> tempDouble;
    monster->setExpBonus(tempDouble);
    file >> tempDouble;
    monster->setExpWhenDied(tempDouble);
    return monster;
}
