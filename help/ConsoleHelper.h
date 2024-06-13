//
// Created by xxxx on 12.06.2022.
//

#ifndef UNTITLED1_CONSOLEHELPER_H
#define UNTITLED1_CONSOLEHELPER_H

#include <cstdlib>
#include <iostream>
#include <vector>
#include "../creatures/Creature.h"
#include "../creatures/CreatureFactory.h"
#include "../game/ActualPlayer.h"

class ConsoleHelper {
public:
    static void clearConsole();
    static void printMainMenu();
    static void printExitMessage();
    static void printPlayerTeamInfo(std::vector<Creature*> & team);
    static void printAvailableCreaturesInfo();
    static void printHumanMoveInfo();
    static void printWrongChoice();
    static void printGameOver();
    static void printCreatureSelection(std::vector<Creature*> &playerTeam);
    static void printEnterEnyKeyToContinue();
    static void printVictory();
    static void printEvolutionNotAvailable();
    static void printAttackInformation(Creature * monster,Creature* enemy);
    static void printSpecialActionInformation(Creature* monster);
    static void printSpecialActionIsNotAvailable(Creature* monster);
    static void printEvolution(Creature* monster);
    static void printAttackHaveMissed();
    static void printNewRoundStartsInfo(std::vector<Creature*> &playerTeam, std::vector<Creature*> &enemies, ActualPlayer actualPlayer);
};


#endif //UNTITLED1_CONSOLEHELPER_H
