#include <iostream>
#include "gameplay.h"
#include <cstdlib>
#include "UI.h"
#define xLength 7
#define yLength 13







int main() {

    srand(time(0));
    int row = 0;
    int column = 0;
    char tablero[xLength][yLength];
    bool turno1 = true;
    bool gameOver = false;

   

    mainMenu(tablero, row, column, turno1, gameOver);

   

}
