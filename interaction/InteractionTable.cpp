//
// Created by xxxx on 05.06.2022.
//

#include "InteractionTable.h"

double InteractionTable::attackEfficiencyTable[6][6] = {
        {-20, 20, 0, 20, 0,0},
        {0,0,-20,20,20,20},
        {0,-20,0,0,20,-20},
        {-20,-20,0,0,20,20},
        {-20,20,0,-20,-20,0},
        {20,0,20,-20,0,-20}
};

double InteractionTable::getAttackEfficiency(Creature *attacker, Creature *defender) {
    return attackEfficiencyTable[attacker->getCreatureType()][defender->getCreatureType()];
}
