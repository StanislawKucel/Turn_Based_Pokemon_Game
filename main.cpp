#include <iostream>

#include "interface/MainMenu.h"
#include <ctime>
#include <cstdlib>

int main() {
    srand(time(NULL));

    MainMenu mainMenu;
    while (mainMenu.getIsRunning()){
        mainMenu.update();
    }

    return 0;
}
