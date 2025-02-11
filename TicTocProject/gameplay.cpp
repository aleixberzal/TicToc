#include <iostream>
#include "UI.h"
#include "table.h"
#define PLAYER 'X'
#define MACHINE 'O'
void gamePlay(char tablero[xLength][yLength], int& row, int& column, bool& turno1) {

    /*Creamos la variable ficha para asignar una en cada turno correspondiente con el ternario*/

    char ficha = turno1 ? 'X' : 'O';
    /*Usamos las operaciones matemáticas para acceder a la memoria de la array introduciendo solo 1, 2 y 3

    1.- fila 1 * 2 - 1 es la fila 1
    2.- fila 2 * 2 - 1 es la fila 2
    3. - fila 3 * 2 - 1 es la fila 3

    Porque las posiciones para acceder a cada fila son en realidad la 1, la 3 y la 5.
        */
    int tableroRow = row * 2 - 1;

    /*Usamos las operaciones matemáticas para acceder a la memoria de la array introduciendo solo 1, 2 y 3

    1.- columna 1 * 4 - 2 es la columna 1
    2.- columna 2 * 4 - 2 es la columna 2
    3. - columna 3 * 4 - 2 es la columna 3

    Porque las posiciones para acceder a cada fila son en realidad la 2, la 6 y la 10.
    */

    int tableroColumn = column * 4 - 2;

    if (tablero[tableroRow][tableroColumn] == ' ') {

        tablero[tableroRow][tableroColumn] = ficha;

    }
}
bool victoryLogic() {

    char tablero[xLength][yLength];
    bool victory = true;

    while (victory) {
        //Lateral
        for (int i = 1; i <= 3; i++) {

            if ((tablero[i * 2 - 1][2] == tablero[i * 2 - 1][6] && tablero[i * 2 - 1][6] == tablero[i * 2 - 1][10]) && tablero[i * 2 - 1][2] != ' ') {
                std::cout << "Has ganado la partida!" << std::endl;
                victory = false;
            }
            else {
                return victory;
            }

        }


        //Vertical
        for (int i = 1; i <= 3; i++) {

            if ((tablero[1][i * 4 - 2] == tablero[3][i * 4 - 2] && tablero[3][i * 4 - 2] == tablero[5][i * 4 - 2]) && tablero[1][i * 4 - 2] != ' ') {
                std::cout << "Has ganado la partida!" << std::endl;
                victory = false;
            }
            else {
                return victory;


            }

        }



        //Left to right

        if ((tablero[1][2] == tablero[3][6] && tablero[3][6] == tablero[5][10]) && tablero[1][2] != ' ') {

            std::cout << "Has ganado la partida!" << std::endl;
            victory = false;
        }
        else {
            return victory;
        }


        //Right to left

        if ((tablero[1][10] == tablero[3][6] && tablero[3][6] == tablero[5][2]) && tablero[1][10] != ' ') {

            std::cout << "Has ganado la partida!" << std::endl;
            victory = false;

        }
        else {
            return victory;
        }

        return 0;

    }
}

void newGame(char tablero[xLength][yLength], int& row, int& column, bool& turno1, bool& victory) {
    createTable(tablero);
    printTable(tablero);

    while (!victory) {

        /*Si es el turno 1 saldrá el primer título, en caso de que no lo sea, saldrá el de después del doble punto*/

        std::cout << (turno1 ? "TURNO DEL JUGADOR 1" : "TURNO DEL JUGADOR 2") << std::endl;

        if (!turno1) {

            do {
                row = rand() % 3 + 1;
                column = rand() % 3 + 1;
            } while (tablero[row * 2 - 1][column * 4 - 2] != ' ');

            /*    std::cout << "I choose the row: " << row << std::endl;
                std::cout << "I choose the column: " << column << std::endl;*/


            updateTable(tablero, row, column, turno1, victory);
            if (victoryLogic()) {

                victory = false;
                mainMenu(tablero, row, column, turno1, victory);

            }
            else {
                victory = true;
            }
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


            updateTable(tablero, row, column, turno1, victory);

            if (victoryLogic()) {

                victory = false;

            }
            else {
                victory = true;
                mainMenu(tablero, row, column, turno1, victory);

            }
            turno1 = !turno1;


        }


    }

}


void loadGame(char tablero[xLength][yLength], int& row, int& column, bool& turno1, bool& gameOver) {

    createTable(tablero);
    printTable(tablero);

    while (!gameOver) {

        /*Si es el turno 1 saldrá el primer título, en caso de que no lo sea, saldrá el de después del doble punto*/

        std::cout << (turno1 ? "TURNO DEL JUGADOR 1" : "TURNO DEL JUGADOR 2") << std::endl;

        if (!turno1) {

            do {
                row = rand() % 3 + 1;
                column = rand() % 3 + 1;
            } while (tablero[row * 2 - 1][column * 4 - 2] != ' ');

            /*    std::cout << "I choose the row: " << row << std::endl;
                std::cout << "I choose the column: " << column << std::endl;*/


            updateTable(tablero, row, column, turno1, gameOver);
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


            updateTable(tablero, row, column, turno1, gameOver);
            turno1 = !turno1;


        }
    }

}


void exitGame() {
    std::cout << "Goodbye!" << std::endl;
}









