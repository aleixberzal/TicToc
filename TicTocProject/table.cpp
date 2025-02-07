#include <iostream>
#include "gameplay.h"
#define xLength 7
#define yLength 13

void printTable(char tablero[xLength][yLength]) {

    for (int i = 0; i < xLength; i++) {
        for (int j = 0; j < yLength; j++) {
            std::cout << tablero[i][j];
        }
        std::cout << std::endl;
    }
}
void updateTable(char tablero[xLength][yLength], int& row, int& column, bool& turno1, bool& victory) {

    gamePlay(tablero, row, column, turno1);
    victoryLogic(tablero);
    printTable(tablero);

}


void createTable(char tablero[xLength][yLength]) {

    for (int i = 0; i < xLength; i++) {
        for (int j = 0; j < yLength; j++) {

            /*Si no es par me imprime los pipes, solo en las posiciones multiples de 4, para que lo
            haga solo cada 4 posiciones y quede bien centrado*/

            if (i % 2 != 0) {
                tablero[i][j] = (j % 4 == 0) ? '|' : ' ';
            }
            else {
                tablero[i][j] = '-';
            }
        }
    }
}
