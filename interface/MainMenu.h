//
// Created by xxxx on 05.06.2022.
//

#ifndef UNTITLED1_MAINMENU_H
#define UNTITLED1_MAINMENU_H

#include "../game/Game.h"
#include "../game/GameState.h"

class MainMenu {
private:
    Game game;
    bool isRunning;
    GameState gameState;

public:
    MainMenu();

    void update();
    bool getIsRunning();
};


#endif //UNTITLED1_MAINMENU_H
