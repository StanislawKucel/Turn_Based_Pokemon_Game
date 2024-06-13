//
// Created by xxxx on 05.06.2022.
//

#include "MainMenu.h"
#include "../help/ConsoleHelper.h"

#include <iostream>


bool MainMenu::getIsRunning() {
    return isRunning;
}

void MainMenu::update() {
    std::string choice = "";
    ConsoleHelper::clearConsole();
    switch (gameState) {
        case MAIN_MENU:
            ConsoleHelper::printMainMenu();
            std::getline(std::cin,choice);
            if (choice == "1"){
                gameState = NEW_GAME;
            }else if(choice == "2"){
                gameState = LOAD_GAME;
            } else if(choice == "3"){
                gameState = EXIT;
            }else{
                //do nothing
            }
            break;
        case LOAD_GAME:
            game.loadFromFile(Game::saveFileName);
            gameState = PLAY;
            break;
        case NEW_GAME:
            game.rebuildGame();
            gameState = PLAY;
            break;
        case PLAY:
            game.run();
            gameState = MAIN_MENU;
            break;
        case EXIT:
            ConsoleHelper::printExitMessage();
            isRunning = false;
            std::getline(std::cin, choice);
            break;
    }
}

MainMenu::MainMenu(): game(),isRunning(true), gameState(MAIN_MENU) {

}

