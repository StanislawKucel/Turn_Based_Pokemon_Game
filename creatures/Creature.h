//
// Created by xxxx on 05.06.2022.
//

#ifndef UNTITLED1_CREATURE_H
#define UNTITLED1_CREATURE_H

#include <string>
#include <fstream>

typedef enum CreatureType{
    WATER = 0,
    EARTH = 1,
    AIR = 2,
    FIRE = 3,
    ICE = 4,
    STEEL = 5
} CreatureType;

class Creature {
protected:
    double strength;
    double dexterity;
    double maxHitPoints;
    double actualHitPoints;
    int specialPower;
    double exp;
    double expBonus;
    double expWhenDied;

    std::string name;

public:
    Creature(double strength, double dexterity, double hitPoints, int specialPower, double exp, double expBonus, const std::string &name);


    // virtual - metoda jest wirtualna to oanzaxza że wykonana zostanie metoda lub jeżeli metoda jest przeciazona w klassach pochodnyh to uruchomi przeciazona metode
    // = 0 - oznacza ze w danej klasie nie ma implementacji tej metody, stad tez klasa z taka deklaracja staje sie klasa abstrakcyjna, w przypadku dziedziczenia po tej klasie nalezy zaimplementowac taka metode


    virtual CreatureType getCreatureType() const = 0;
    virtual std::string getCreatureTypeString() const = 0;
    void attack(Creature* opponent);
    virtual bool specialAction(Creature* opponent) = 0;
    bool evolution();

    virtual double getStrength() const;

    virtual double getDexterity() const;

    virtual double getActualHitPoints() const;

    int getSpecialPower() const;

    double getExp() const;

    double getExpBonus() const;

    const std::string &getName() const;

    bool isAlive() const;

    void saveToFile(std::ofstream &file);
    static Creature* loadFromFile(std::ifstream &file);

    void setStrength(double strength);

    void setDexterity(double dexterity);

    void setMaxHitPoints(double maxHitPoints);

    void setActualHitPoints(double actualHitPoints);

    void setSpecialPower(int specialPower);

    void setExp(double exp);

    void setExpBonus(double expBonus);

    void setExpWhenDied(double expWhenDied);
};





#endif //UNTITLED1_CREATURE_H
