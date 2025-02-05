#include <iostream>
#include "gameplay.h"
#include <cstdlib>
#define xLength 7
#define yLength 13

void gamePlay(char tablero[xLength][yLength], int row, int column, bool turno1) {

    /*Creamos la variable ficha para asignar una en cada turno correspondiente con el ternario*/

    char ficha = turno1 ? 'X' : 'O';
    /*Usamos las operaciones matemáticas para acceder a la memoria de la array introduciendo solo 1, 2 y 3
    1.- fila 1 * 2 - 1 es la fila 1
    2.- fila 2 * 2 - 1 es la fila 2
    3. - fila 3 * 2 - 1 es la fila 1 

    Porque las posiciones para acceder a cada fila son en realidad la 1, la 3 y la 5.
        */
    int tableroRow = row * 2 - 1;
    
    /*Usamos las operaciones matemáticas para acceder a la memoria de la array introduciendo solo 1, 2 y 3
    
1.- fila 1 * 4 - 2 es la fila 1
2.- fila 2 * 4 - 2 es la fila 2
3. - fila 3 * 4 - 2 es la fila 1

Porque las posiciones para acceder a cada fila son en realidad la 2, la 6 y la 10.
    */

    int tableroColumn = column * 4 - 2;

    if (tablero[tableroRow][tableroColumn] == ' ') {

        tablero[tableroRow][tableroColumn] = ficha;

    }
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

    srand(time(0));
    int row, column;
    char tablero[xLength][yLength];
    bool turno1 = true;

    createTable(tablero);
    printTable(tablero);

    while (true) { 

        /*Si es el turno 1 saldrá el primer título, en caso de que no lo sea, saldrá el de después del doble punto*/

        std::cout << (turno1 ? "TURNO DEL JUGADOR 1" : "TURNO DEL JUGADOR 2") << std::endl;

        if (!turno1) {

            do {
                row = rand() % 3 + 1;
                column = rand() % 3 + 1;
            } while (tablero[row * 2 - 1][column * 4 - 2] != ' ');

            std::cout << "I choose the row: " << row << std::endl;
            std::cout << "I choose the column: " << column << std::endl;

            updateTable(tablero, row, column, turno1);
            turno1 = !turno1;
        }
        else {
            do {
                std::cout << "Choose a row (1-3): ";
                std::cin >> row;
                std::cout << "Choose a column (1-3): ";
                std::cin >> column;

                if (row < 1 || row > 3 || column < 1 || column > 3 || tablero[row * 2 - 1][column * 4 - 2] != ' ') {
                    std::cout << "Posicion no valida, vuelve a intentarlo.\n";
                }
            } while (row < 1 || row > 3 || column < 1 || column > 3 || tablero[row * 2 - 1][column * 4 - 2] != ' ');

            updateTable(tablero, row, column, turno1);
            turno1 = !turno1; 
        }
    }


}
