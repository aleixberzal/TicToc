#include <iostream>
#include "gameplay.h"
#include <cstdlib>
#define xLength 7
#define yLength 13

void gamePlay(char tablero[xLength][yLength], int row, int column, bool turno1) {

    /*Creamos la variable ficha para asignar una en cada turno correspondiente con el ternario*/

    char ficha = turno1 ? 'X' : 'O';
    /*Usamos las operaciones matem�ticas para acceder a la memoria de la array introduciendo solo 1, 2 y 3
    
    1.- fila 1 * 2 - 1 es la fila 1
    2.- fila 2 * 2 - 1 es la fila 2
    3. - fila 3 * 2 - 1 es la fila 3

    Porque las posiciones para acceder a cada fila son en realidad la 1, la 3 y la 5.
        */
    int tableroRow = row * 2 - 1;
    
    /*Usamos las operaciones matem�ticas para acceder a la memoria de la array introduciendo solo 1, 2 y 3
    
    1.- columna 1 * 4 - 2 es la fila 1
    2.- columna 2 * 4 - 2 es la fila 2
    3. - columna 3 * 4 - 2 es la fila 3

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
void victoryLogic(char tablero[xLength][yLength], int row, int column, bool turno1, bool gameOver) {


    /*Chequeamos si alguna row es del mismo s�mbolo*/
    for (int i = 0; i <= 2; i++) {

        if (tablero[i][0] == tablero[i][1] && tablero[i][1] == tablero[i][2] && tablero[i][0] != 0) {

            if (turno1) {
                std::cout << "El ganador es el jugador IA" << std::endl;
                gameOver = true;
            }
            else {
                std::cout << "El ganador es el jugador humano" << std::endl;
                gameOver = true;
            }
        }
    }
    /*Chequeamos si alguna fila es el mismo s�mbolo*/
    for (int i = 0; i <= 2; i++) {

        if (tablero[0][i] == tablero[1][i] && tablero[1][i] == tablero[2][i] && tablero[0][i] != 0) {

            if (turno1) {
                std::cout << "El ganador es el jugador IA" << std::endl;
                gameOver = true;
            }
            else {
                std::cout << "El ganador es el jugador humano" << std::endl;
                gameOver = true;
            }
        }
    }
}
void newGame(char tablero[xLength][yLength], int row, int column, bool turno1, bool gameOver) {
    
    createTable(tablero);
    printTable(tablero);

    while (!gameOver) {

        /*Si es el turno 1 saldr� el primer t�tulo, en caso de que no lo sea, saldr� el de despu�s del doble punto*/

        std::cout << (turno1 ? "TURNO DEL JUGADOR 1" : "TURNO DEL JUGADOR 2") << std::endl;

        if (!turno1) {

            do {
                row = rand() % 3 + 1;
                column = rand() % 3 + 1;
            } while (tablero[row * 2 - 1][column * 4 - 2] != ' ');

            std::cout << "I choose the row: " << row << std::endl;
            std::cout << "I choose the column: " << column << std::endl;

            updateTable(tablero, row, column, turno1);
            victoryLogic(tablero, row, column, turno1, gameOver);
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
void loadGame (char tablero[xLength][yLength], int row, int column, bool turno1, bool gameOver) {

    createTable(tablero);
    printTable(tablero);

    while (!gameOver) {

        /*Si es el turno 1 saldr� el primer t�tulo, en caso de que no lo sea, saldr� el de despu�s del doble punto*/

        std::cout << (turno1 ? "TURNO DEL JUGADOR 1" : "TURNO DEL JUGADOR 2") << std::endl;

        if (!turno1) {

            do {
                row = rand() % 3 + 1;
                column = rand() % 3 + 1;
            } while (tablero[row * 2 - 1][column * 4 - 2] != ' ');

            std::cout << "I choose the row: " << row << std::endl;
            std::cout << "I choose the column: " << column << std::endl;

            updateTable(tablero, row, column, turno1);
            victoryLogic(tablero, row, column, turno1, gameOver);
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

void exit() {
    std::cout << "Goodbye!" << std::endl;
    }
    void mainMenu(char tablero[xLength][yLength], int row, int column, bool turno1, bool gameOver){
        std::cout << "TIC TAC TOE" << std::endl;

        int userInput;

        std::cout << "1.- New game\n2.- Load game\n3.- Exit\nChoose an option(1-3): ";
        std::cin >> userInput;
        
        switch (userInput) {
        case 1:
            if (userInput == 1) {
                newGame(tablero, row, column, turno1, gameOver);
            }
            break;
        case 2:
            if (userInput == 2) {
                loadGame(tablero, row, column, turno1, gameOver);
            }
        case 3: 
            if (userInput == 3) {
                exit();
            }
        }

            
    }

    /*Chequeamos si la diagonal de 1-1 es el mismo s�mbolo*/
    /*Chequeamos si la diagonal de 1-3 es el mismo s�mbolo*/

int main() {

    srand(time(0));
    int row = 0;
    int column = 0;
    char tablero[xLength][yLength];
    bool turno1 = true;
    bool gameOver = false;

   

    mainMenu(tablero, row, column, turno1, gameOver);

   

}
