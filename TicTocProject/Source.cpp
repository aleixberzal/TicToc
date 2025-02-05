#include <iostream>
#include "gameplay.h"

#define xLength 7
#define yLength 13

void gamePlay(char updateTablero[xLength][yLength], int& row, int& column, int& rowUP, int& columnUP, bool& turno1) {

    firstRow(updateTablero, row, column, rowUP, columnUP, turno1);
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

void updateTable(char updateTablero[xLength][yLength], int row, int column, int rowUP, int columnUP, bool turno1) {
    // Copiamos el tablero original a updateTablero
    for (int i = 0; i < xLength; i++) {
        for (int j = 0; j < yLength; j++) {
            updateTablero[i][j] = updateTablero[i][j]; // Asegúrate de no sobrescribir
        }
    }
    
    gamePlay(updateTablero, row, column, rowUP, columnUP, turno1);
  
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
        std::cout << "Choose a row: " << std::endl;
        std::cin >> row;

        std::cout << "Choose a column: " << std::endl;
        std::cin >> column;

     
            // Copiamos el tablero original a la versión de actualización
            for (int i = 0; i < xLength; i++) {
                for (int j = 0; j < yLength; j++) {
                    updateTablero[i][j] = tablero[i][j];
                }
            }

            // Actualizamos el tablero con la nueva posición

            updateTable(updateTablero, row, column, rowUP, columnUP, turno1);
        
            // DETERMINAR LA PRIMERA FILA
            if (row < 1 || row > 3 || column < 1 || column > 3) {

                std::cout << "Posicion no valida, vuelve a tirar" << std::endl;

                turno1 = true;

                std::cout << "Choose a row: " << std::endl;
                std::cin >> row;

                std::cout << "Choose a column: " << std::endl;
                std::cin >> column;


                // Copiamos el tablero original a la versión de actualización
                for (int i = 0; i < xLength; i++) {
                    for (int j = 0; j < yLength; j++) {
                        updateTablero[i][j] = tablero[i][j];
                    }
                }

                // Actualizamos el tablero con la nueva posición

                updateTable(updateTablero, row, column, rowUP, columnUP, turno1);

            }
            else {
                turno1 = false;
            }

    }

    return 0;
}
