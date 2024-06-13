//
// Created by xxxx on 12.06.2022.
//


#include "ConsoleHelper.h"

void ConsoleHelper::clearConsole() {
    system("CLS");
}

void ConsoleHelper::printMainMenu() {
    std::cout << "#####################################" <<std::endl;
    std::cout << "############# Main menu #############" <<std::endl;
    std::cout << "#####################################" <<std::endl;
    std::cout << "###### 1 - NEW GAME #################" <<std::endl;
    std::cout << "###### 2 - LOAD GAME ################" <<std::endl;
    std::cout << "###### 3 - EXIT #####################" <<std::endl;
    std::cout << "#####################################" <<std::endl;
}

void ConsoleHelper::printExitMessage() {
    std::cout << "#####################################" <<std::endl;
    std::cout << "#### Thank you for your time ########" <<std::endl;
    std::cout << "###### Press enter to exit ##########" <<std::endl;
    std::cout << "#####################################" <<std::endl;
}

void ConsoleHelper::printPlayerTeamInfo(std::vector<Creature*> & team) {
    std::cout << "#####################################" <<std::endl;
    std::cout << "#### Your team: #####################" <<std::endl;
    for (int i = 0; i < team.size(); ++i) {
        std::cout << team[i]->getName() << " (" << team[i]->getCreatureTypeString() << ")" << std::endl;
    }
    std::cout << "#####################################" <<std::endl;
}

void ConsoleHelper::printAvailableCreaturesInfo() {
    std::cout << "#### Available creatures: ###########" <<std::endl;
    std::cout << CreatureFactory::getCreaturesInfo() ;
    std::cout << "#####################################" <<std::endl;
    std::cout << "Press creature number to add to your team:" <<std::endl;
}

void ConsoleHelper::printHumanMoveInfo() {
    std::cout << "#####################################" <<std::endl;
    std::cout << "######### SELECT ACTION #############" <<std::endl;
    std::cout << "#####################################" <<std::endl;
    std::cout << "###### 1 - ATTACK ###################" <<std::endl;
    std::cout << "###### 2 - SPECIAL POWER ############" <<std::endl;
    std::cout << "###### 3 - EVOLUTION ################" <<std::endl;
    std::cout << "###### 4 - MONSTER SWAP #############" <<std::endl;
    std::cout << "###### 5 - SAVE AND EXIT ############" <<std::endl;
    std::cout << "#####################################" <<std::endl;
}

void ConsoleHelper::printWrongChoice() {
    std::cout << "#####################################" <<std::endl;
    std::cout << "######### WRONG CHOICE ##############" <<std::endl;
    std::cout << "####### PLEASE TRY AGAIN ############" <<std::endl;
    std::cout << "#####################################" <<std::endl;
}

void ConsoleHelper::printGameOver() {
    std::cout << "#####################################" <<std::endl;
    std::cout << "##### GAME OVER YOU WEAKLING ########" <<std::endl;
    std::cout << "#### GOOD LUCK NEXT TIME LOOSER #####" <<std::endl;
    std::cout << "#####################################" <<std::endl;
}

void ConsoleHelper::printCreatureSelection(std::vector<Creature *> &playerTeam) {
    std::cout << "#####################################" <<std::endl;
    std::cout << "####### SELECT CREATURE #############" <<std::endl;
    std::cout << "#####################################" <<std::endl;
    for (int i = 0; i < playerTeam.size(); ++i) {
        if(playerTeam[i]->isAlive()){
            std::cout << (i+1) << " " << playerTeam[i]->getName() << " is Alive! HP: " << playerTeam[i]->getActualHitPoints() <<" Strength: " << playerTeam[i]->getStrength() << " Dexterity: " << playerTeam[i]->getDexterity() << " EXP: " << playerTeam[i]->getExp() << "/" << playerTeam[i]->getExpBonus() << std::endl;
        }else{
            std::cout << (i+1) << " " << playerTeam[i]->getName() << " is Dead!" << std::endl;
        }
    }
}

void ConsoleHelper::printEnterEnyKeyToContinue() {
    std::cout << "#####################################" <<std::endl;
    std::cout << "#### Press enter to continue ########" <<std::endl;
    std::cout << "#####################################" <<std::endl;
}

void ConsoleHelper::printVictory() {
    std::cout << "#####################################" <<std::endl;
    std::cout << "##### CONGRATS YOU TRICKY GUY #######" <<std::endl;
    std::cout << "#### NEXT TIME YOU WILL PERISH ######" <<std::endl;
    std::cout << "#####################################" <<std::endl;
}

void ConsoleHelper::printEvolutionNotAvailable() {
    std::cout << "#####################################" <<std::endl;
    std::cout << "### EVOLUTION IS NOT AVAILABLE ######" <<std::endl;
    std::cout << "#####################################" <<std::endl;
}

void ConsoleHelper::printAttackInformation(Creature * monster,Creature* enemy) {
    std::cout << "#####################################" <<std::endl;
    std::cout << monster->getName() << " have Attacked: " << enemy->getName() <<" Which now have " << enemy->getActualHitPoints() << " Health "<< std::endl;
    if(enemy->isAlive() == false){
        std::cout << "Creature " << enemy->getName() << " Have Died " << std::endl;
    }
    std::cout << "#####################################" <<std::endl;
}

void ConsoleHelper::printSpecialActionInformation(Creature* monster) {
    std::cout << "#####################################" <<std::endl;
    std::cout << "Special power has been used by " << monster->getName() << std::endl;
    std::cout << "#####################################" <<std::endl;
}

void ConsoleHelper::printSpecialActionIsNotAvailable(Creature* monster) {
    std::cout << "#####################################" <<std::endl;
    std::cout << "Monster: " << monster->getName() << " Have no More charges of his special power! "<< std::endl;
    std::cout << "#####################################" <<std::endl;

}

void ConsoleHelper::printEvolution(Creature *monster) {
    std::cout << "#####################################" <<std::endl;
    std::cout << "Monster: " << monster->getName() << " Have evolved "<< std::endl;
    std::cout << "#####################################" <<std::endl;

}

void ConsoleHelper::printAttackHaveMissed() {
    std::cout << "#####################################" <<std::endl;
    std::cout << "####### ATTACK HAVE MISSED ##########" <<std::endl;
    std::cout << "#####################################" <<std::endl;
}

void ConsoleHelper::printNewRoundStartsInfo(std::vector<Creature*> &playerTeam, std::vector<Creature*> &enemies, ActualPlayer actualPlayer) {
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "#####################################" <<std::endl;
    std::cout << "######### NEW ROUND STARTS ##########" <<std::endl;
    std::cout << "#####################################" <<std::endl;
    std::cout << "Player team:"<<std::endl;
    for (int i = 0; i < playerTeam.size(); ++i) {
        if(playerTeam[i]->isAlive()){
            std::cout << (i+1) << " " << playerTeam[i]->getName() << " is Alive! HP: " << playerTeam[i]->getActualHitPoints() <<" Strength: " << playerTeam[i]->getStrength() << " Dexterity: " << playerTeam[i]->getDexterity() << " EXP: " << playerTeam[i]->getExp() << "/" << playerTeam[i]->getExpBonus() << std::endl;
        }else{
            std::cout << (i+1) << " " << playerTeam[i]->getName() << " is Dead!" << std::endl;
        }
    }
    std::cout << "#####################################" <<std::endl;
    std::cout << "Enemy team:"<<std::endl;
    for (int i = 0; i < enemies.size(); ++i) {
        if(enemies[i]->isAlive()){
            std::cout << (i+1) << " " << enemies[i]->getName() << " is Alive! HP: " << enemies[i]->getActualHitPoints() <<" Strength: " << enemies[i]->getStrength() << " Dexterity: " << enemies[i]->getDexterity() << " EXP: " << enemies[i]->getExp() << "/" << enemies[i]->getExpBonus() << std::endl;
        }else{
            std::cout << (i+1) << " " << enemies[i]->getName() << " is Dead!" << std::endl;
        }
    }
    std::cout << "#####################################" <<std::endl;
    if(actualPlayer == HUMAN){
        std::cout << "HUMAN PLAYS"<<std::endl;
    }else{
        std::cout << "COMPUTER PLAYS"<<std::endl;
    }
    std::cout << "#####################################" <<std::endl;
}
