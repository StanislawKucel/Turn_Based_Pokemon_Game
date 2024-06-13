//
// Created by xxxx on 05.06.2022.
//

#ifndef UNTITLED1_GAME_H
#define UNTITLED1_GAME_H

#include <iostream>
#include <chrono>
#include <thread>
#include <vector>
#include <sstream>

#include "../creatures/Creature.h"
#include "ActualPlayer.h"

class Game {
private:
    std::vector<Creature*> playerTeam;
    std::vector<std::vector<Creature*>> levels_enemies;
    ActualPlayer actualPlayer;


    void clearPlayerTeam();
    void clearLevelsEnemies();
public:
    static std::string saveFileName;
    void saveToFile(std::string fileName);
    void loadFromFile(std::string fileName);

    void rebuildGame();
    void run();

    Game();
    ~Game();
};


#endif //UNTITLED1_GAME_H
