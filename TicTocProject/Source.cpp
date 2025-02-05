#include <iostream>
#include "gameplay.h"

#define xLength 7
#define yLength 13

void gamePlay(char tablero[xLength][yLength], int row, int column, bool turno1) {
    char ficha = turno1 ? 'X' : 'O';
    int tableroRow = row * 2 - 1;
    int tableroColumn = column * 4 - 2;

    if (tablero[tableroRow][tableroColumn] == ' ') {
        tablero[tableroRow][tableroColumn] = ficha;
    }
}

void createTable(char tablero[xLength][yLength]) {
    for (int i = 0; i < xLength; i++) {
        for (int j = 0; j < yLength; j++) {
            if (i % 2 != 0) {
                tablero[i][j] = (j % 4 == 0) ? '|' : ' ';
            }
            else {
                tablero[i][j] = '-';
            }
        }
    }
}

void printTable(char tablero[xLength][yLength]) {
    for (int i = 0; i < xLength; i++) {
        for (int j = 0; j < yLength; j++) {
            std::cout << tablero[i][j];
        }
        std::cout << std::endl;
    }
}

void updateTable(char tablero[xLength][yLength], int row, int column, bool turno1) {
    gamePlay(tablero, row, column, turno1);
    printTable(tablero);
}

int main() {
    int row, column;
    char tablero[xLength][yLength];
    bool turno1 = true;

    createTable(tablero);
    printTable(tablero);

    while (true) { // Se repite el juego hasta que se decida detenerlo manualmente
        std::cout << (turno1 ? "TURNO DEL JUGADOR 1" : "TURNO DEL JUGADOR 2") << std::endl;

        do {
            std::cout << "Choose a row (1-3): ";
            std::cin >> row;
            std::cout << "Choose a column (1-3): ";
            std::cin >> column;

            if (row < 1 || row > 3 || column < 1 || column > 3) {
                std::cout << "Posici\xF3n no v\xE1lida, vuelve a intentarlo.\n";
            }
        } while (row < 1 || row > 3 || column < 1 || column > 3); // Repite hasta que el movimiento sea válido

        updateTable(tablero, row, column, turno1);
        turno1 = !turno1; // Cambia de turno
    }

    return 0;
}
