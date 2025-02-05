#include <iostream>
#include "gameplay.h"

#define xLength 7
#define yLength 13

void gamePlay(char updateTablero[xLength][yLength], int& row, int& column, int& rowUP, int& columnUP) {

    firstRow(updateTablero, row, column, rowUP, columnUP);
    secondRow(updateTablero, row, column, rowUP, columnUP);
    thirdRow(updateTablero, row, column, rowUP, columnUP);
}

void createTable(char tablero[xLength][yLength]) {
    // Inicializamos el tablero con los caracteres apropiados.
    for (int i = 0; i < xLength; i++) {
        for (int j = 0; j < yLength; j++) {
            if (i % 2 != 0) {
                if (j % 4 == 0) {
                    tablero[i][j] = '|';
                }
                else {
                    tablero[i][j] = ' ';
                }
            }
            else {
                tablero[i][j] = '-';
            }
        }
    }

    // Imprimimos el tablero.
    for (int i = 0; i < xLength; i++) {
        for (int j = 0; j < yLength; j++) {
            std::cout << tablero[i][j];
        }
        std::cout << std::endl;
    }
}

void updateTable(char updateTablero[xLength][yLength], int row, int column, int rowUP, int columnUP) {
    // Copiamos el tablero original a updateTablero
    for (int i = 0; i < xLength; i++) {
        for (int j = 0; j < yLength; j++) {
            updateTablero[i][j] = updateTablero[i][j]; // Asegúrate de no sobrescribir
        }
    }
    
    gamePlay(updateTablero, row, column, rowUP, columnUP);
  
    // Imprimimos el tablero actualizado.
    for (int i = 0; i < xLength; i++) {
        for (int j = 0; j < yLength; j++) {
            std::cout << updateTablero[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    int row, column;
    int rowUP = 0;
    int columnUP = 0;
    char tablero[xLength][yLength];
    char updateTablero[xLength][yLength];
    bool turno1 = true;

    // Creamos el tablero inicial
    createTable(tablero);

    if (turno1) {
        std::cout << "Choose a row (must be 1): " << std::endl;
        std::cin >> row;

        std::cout << "Choose a column (must be 1): " << std::endl;
        std::cin >> column;

     
            // Copiamos el tablero original a la versión de actualización
            for (int i = 0; i < xLength; i++) {
                for (int j = 0; j < yLength; j++) {
                    updateTablero[i][j] = tablero[i][j];
                }
            }

            // Actualizamos el tablero con la nueva posición

            updateTable(updateTablero, row, column, rowUP, columnUP);
        
       

        turno1 = false;
    }

    return 0;
}
