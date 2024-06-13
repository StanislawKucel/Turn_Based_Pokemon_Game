//
// Created by xxxx on 05.06.2022.
//

#ifndef UNTITLED1_INTERACTIONTABLE_H
#define UNTITLED1_INTERACTIONTABLE_H

#include "../creatures/Creature.h"

class InteractionTable {
private:
    static double attackEfficiencyTable[6][6];

public:
    static double getAttackEfficiency(Creature *attacker, Creature *defender);
};


#endif //UNTITLED1_INTERACTIONTABLE_H
