#include <iostream>
#include "gameplay.h"
#define xLength 7
#define yLength 13

void mainMenu(char tablero[xLength][yLength], int& row, int& column, bool& turno1, bool& victory) {
    std::cout << "TIC TAC TOE" << std::endl;

    int userInput;

    std::cout << "1.- New game\n2.- Load game\n3.- Exit\nChoose an option(1-3): ";
    std::cin >> userInput;

    switch (userInput) {
    case 1:
        if (userInput == 1) {
            newGame(tablero, row, column, turno1, victory);
        }
        break;
    case 2:
        if (userInput == 2) {
            loadGame(tablero, row, column, turno1, victory);
        }
        break;
    case 3:
        if (userInput == 3) {
            exitGame();
        }
        break;
    }


}