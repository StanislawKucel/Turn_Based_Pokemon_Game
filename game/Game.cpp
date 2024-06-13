//
// Created by xxxx on 05.06.2022.
//

#include "Game.h"
#include "GameParameters.h"
#include "../creatures/CreatureFactory.h"
#include "../help/ConsoleHelper.h"
#include <fstream>

std::string Game::saveFileName = "game.txt";

void Game::saveToFile(std::string fileName) {
    std::ofstream file(fileName);

    file << actualPlayer << std::endl;
    file << playerTeam.size() << std::endl;
    for (int i = 0; i < playerTeam.size(); ++i) {
        playerTeam[i]->saveToFile(file);
        file << std::endl;
    }
    file << levels_enemies.size() << std::endl;
    for (int i = 0; i < levels_enemies.size(); ++i) {
        file << levels_enemies[i].size() << std::endl;
        for (int j = 0; j < levels_enemies[i].size(); ++j) {
            levels_enemies[i][j]->saveToFile(file);
            file << std::endl;
        }
    }

    file.close();
}

void Game::loadFromFile(std::string fileName) {
    clearPlayerTeam();
    clearLevelsEnemies();

    std::ifstream file(fileName);

    int temp;
    std::string tempStr;
    double tempDouble;
    file >> temp;
    if (temp == HUMAN) {
        actualPlayer = HUMAN;
    } else {
        actualPlayer = ENEMY;
    }
    file >> temp;
    for (int i = 0; i < temp; ++i) {
        playerTeam.push_back(Creature::loadFromFile(file));
    }
    file >> temp;
    for (int i = 0; i < temp; ++i) {
        int temp2;
        file >> temp2;
        std::vector<Creature *> levelEnemies;
        for (int j = 0; j < temp2; ++j) {
            levelEnemies.push_back(Creature::loadFromFile(file));
        }
        levels_enemies.push_back(levelEnemies);
    }
    file.close();
}

void Game::rebuildGame() {
    clearPlayerTeam();
    clearLevelsEnemies();
    int counter = 0;
    std::string choice;

    //prepare player team creatures
    while (counter < PLAYER_TEAM_CREATURES_NUMBER) {
        ConsoleHelper::clearConsole();
        ConsoleHelper::printPlayerTeamInfo(playerTeam);
        ConsoleHelper::printAvailableCreaturesInfo();
        std::getline(std::cin, choice);
        Creature *newCreature = nullptr;
        if (choice == "1") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[0]);
        } else if (choice == "2") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[1]);
        } else if (choice == "3") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[2]);
        } else if (choice == "4") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[3]);
        } else if (choice == "5") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[4]);
        } else if (choice == "6") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[5]);
        } else if (choice == "7") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[6]);
        } else if (choice == "8") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[7]);
        } else if (choice == "9") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[8]);
        } else if (choice == "10") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[9]);
        } else if (choice == "11") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[10]);
        } else if (choice == "12") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[11]);
        } else if (choice == "13") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[12]);
        } else if (choice == "14") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[13]);
        } else if (choice == "15") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[14]);
        } else if (choice == "16") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[15]);
        } else if (choice == "17") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[16]);
        } else if (choice == "18") {
            newCreature = CreatureFactory::createCreature(CreatureFactory::creaturesNames[17]);
        }
        if (newCreature != nullptr) {
            playerTeam.push_back(newCreature);
            counter++;
        }
    }

    //prepare levels enemies creatures
    for (int i = 0; i < LEVELS_ENEMIES_NUMBERS.size(); ++i) {
        std::vector<Creature *> levelEnemies;
        for (int j = 0; j < LEVELS_ENEMIES_NUMBERS[i]; ++j) {
            std::string creatureName = CreatureFactory::creaturesNames[rand() % CreatureFactory::creaturesNames.size()];
            levelEnemies.push_back(CreatureFactory::createCreature(creatureName));
        }
        levels_enemies.push_back(levelEnemies);
    }

    actualPlayer = ActualPlayer::HUMAN;
}

void Game::run() {
    std::string choice;
    Creature *playerActualCreature = nullptr;
    Creature *enemyActualCreature = nullptr;
    int actualLevelIndex = 0;
    int exit = false;
    while (true) {
        if (playerActualCreature == nullptr) {
            //check game over conditions
            bool gameOver = true;
            for (int i = 0; i < playerTeam.size(); ++i) {
                if (playerTeam[i]->isAlive()) {
                    gameOver = false;
                    break;
                }
            }
            if (gameOver == true) {
                ConsoleHelper::printGameOver();
                break;
            }

            ConsoleHelper::printCreatureSelection(playerTeam);
            int creatureNumber = 0;
            while (true) {
                std::getline(std::cin, choice);
                std::stringstream ss;
                ss.str(choice);
                if (ss >> creatureNumber) {
                    if (creatureNumber >= 1 && creatureNumber <= playerTeam.size() &&
                        playerTeam[creatureNumber - 1]->isAlive()) {
                        break;
                    }
                }
                std::cout << "Enter alive creature number!" << std::endl;
            }
            playerActualCreature = playerTeam[creatureNumber - 1];
        }

        if (enemyActualCreature == nullptr) {
            bool nextLevel = true;
            for (int i = 0; i < levels_enemies[actualLevelIndex].size(); ++i) {
                if (levels_enemies[actualLevelIndex][i]->isAlive()) {
                    nextLevel = false;
                    enemyActualCreature = levels_enemies[actualLevelIndex][i];
                    break;
                }
            }
            if (nextLevel == true) {
                actualLevelIndex++;
                if (actualLevelIndex >= levels_enemies.size()) {
                    ConsoleHelper::printVictory();
                    break;
                }
                enemyActualCreature = levels_enemies[actualLevelIndex][0];
            }
        }

        ConsoleHelper::printNewRoundStartsInfo(playerTeam, levels_enemies[actualLevelIndex], actualPlayer);

        //player and enemy plays
        switch (actualPlayer) {
            case HUMAN:
                while (true) {
                    ConsoleHelper::printHumanMoveInfo();
                    std::getline(std::cin, choice);
                    if (choice == "1") {
                        playerActualCreature->attack(enemyActualCreature);
                        if (!enemyActualCreature->isAlive()) {
                            enemyActualCreature = nullptr;
                        }
                        break;
                    } else if (choice == "2") {
                        if (playerActualCreature->specialAction(enemyActualCreature)) {
                            ConsoleHelper::printSpecialActionInformation(playerActualCreature);
                            if (!enemyActualCreature->isAlive()) {
                                enemyActualCreature = nullptr;
                            }
                            break;
                        } else {
                            ConsoleHelper::printSpecialActionIsNotAvailable(playerActualCreature);
                        }
                    } else if (choice == "3") {
                        if (playerActualCreature->evolution()) {
                            ConsoleHelper::printEvolution(playerActualCreature);
                            break;
                        } else {
                            ConsoleHelper::printEvolutionNotAvailable();
                        }
                    } else if (choice == "4") {
                        ConsoleHelper::printCreatureSelection(playerTeam);
                        int creatureNumber = 0;
                        while (true) {
                            std::getline(std::cin, choice);
                            std::stringstream ss;
                            ss.str(choice);
                            if (ss >> creatureNumber) {
                                if (creatureNumber >= 1 && creatureNumber <= playerTeam.size() &&
                                    playerTeam[creatureNumber - 1]->isAlive()) {
                                    break;
                                }
                            }
                            std::cout << "Enter alive creature number!" << std::endl;
                        }
                        playerActualCreature = playerTeam[creatureNumber - 1];
                        break;
                    } else if (choice == "5") {
                        saveToFile(saveFileName);
                        exit = true;
                        break;
                    } else {
                        ConsoleHelper::printWrongChoice();
                    }
                }
                break;
            case ENEMY:
                while (true) {
                    int enemyChoice = rand() % 3;
                    if (enemyChoice == 0) {
                        enemyActualCreature->attack(playerActualCreature);
                        if (!playerActualCreature->isAlive()) {
                            playerActualCreature = nullptr;
                        }
                        break;
                    } else if (enemyChoice == 1) {
                        if (enemyActualCreature->specialAction(playerActualCreature)) {
                            ConsoleHelper::printSpecialActionInformation(enemyActualCreature);
                            if (!playerActualCreature->isAlive()) {
                                playerActualCreature = nullptr;
                            }
                            break;
                        }
                    } else {
                        if (enemyActualCreature->evolution()) {
                            ConsoleHelper::printEvolution(enemyActualCreature);
                            break;
                        }
                    }
                }
                break;
        }

        if (exit) {
            break;
        }

        //next player selection
        switch (actualPlayer) {
            case HUMAN:
                actualPlayer = ENEMY;
                break;
            case ENEMY:
                actualPlayer = HUMAN;
                break;
        }
    }
    ConsoleHelper::printEnterEnyKeyToContinue();
    std::getline(std::cin, choice);
}

Game::Game() {

}

Game::~Game() {
    clearPlayerTeam();
    clearLevelsEnemies();
}

void Game::clearPlayerTeam() {
    for (int i = 0; i < playerTeam.size(); ++i) {
        if (playerTeam[i] != nullptr) {
            delete playerTeam[i];
        }
    }
    playerTeam.clear();
}

void Game::clearLevelsEnemies() {
    for (int i = 0; i < levels_enemies.size(); ++i) {
        for (int j = 0; j < levels_enemies[i].size(); ++j) {
            if (levels_enemies[i][j] != nullptr) {
                delete levels_enemies[i][j];
            }
        }
        levels_enemies[i].clear();
    }
    levels_enemies.clear();
}
