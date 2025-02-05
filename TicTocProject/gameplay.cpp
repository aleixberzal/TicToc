#include <iostream>

#define xLength 7
#define yLength 13


void firstRow(char updateTablero[xLength][yLength], int& row, int& column, int& rowUP, int& columnUP, bool& turno1) {

   
    if (turno1) {
        if (row == 1 && column == 1) {
            int rowUP = 1;
            int columnUP = 2;
            updateTablero[rowUP][columnUP] = 'X';
        }
        if (row == 1 && column == 2) {
            int rowUP = 1;
            int columnUP = 6;
            updateTablero[rowUP][columnUP] = 'X';
        }
        if (row == 1 && column == 3) {
            int rowUP = 1;
            int columnUP = 10;
            updateTablero[rowUP][columnUP] = 'X';
        }
    }
    else {
        if (row == 1 && column == 1) {
            int rowUP = 1;
            int columnUP = 2;
            updateTablero[rowUP][columnUP] = 'O';
        }
        if (row == 1 && column == 2) {
            int rowUP = 1;
            int columnUP = 6;
            updateTablero[rowUP][columnUP] = 'O';
        }
        if (row == 1 && column == 3) {
            int rowUP = 1;
            int columnUP = 10;
            updateTablero[rowUP][columnUP] = 'O';
        }
    }
       
   
}
void secondRow(char updateTablero[xLength][yLength], int& row, int& column, int& rowUP, int& columnUP, bool& turno1) {

    //DETERMINAR LA SEGUNA FILA
    if (turno1){
    if (row == 2 && column == 1) {
        int rowUP = 3;
        int columnUP = 2;
        updateTablero[rowUP][columnUP] = 'X';
    }
    if (row == 2 && column == 2) {
        int rowUP = 3;
        int columnUP = 6;
        updateTablero[rowUP][columnUP] = 'X';
    }
    if (row == 2 && column == 3) {
        int rowUP = 3;
        int columnUP = 10;
        updateTablero[rowUP][columnUP] = 'X';
    }
}
    else {
        if (row == 3 && column == 1) {
            int rowUP = 5;
            int columnUP = 2;
            updateTablero[rowUP][columnUP] = 'O';
        }
        if (row == 3 && column == 2) {
            int rowUP = 5;
            int columnUP = 6;
            updateTablero[rowUP][columnUP] = 'O';
        }
        if (row == 3 && column == 3) {
            int rowUP = 5;
            int columnUP = 10;
            updateTablero[rowUP][columnUP] = 'O';
        }
    }

}
void thirdRow(char updateTablero[xLength][yLength], int& row, int& column, int& rowUP, int& columnUP, bool& turno1) {

    //DETERMINAR LA ÚLTIMA FILA
    if (turno1) {

        if (row == 3 && column == 1) {
            int rowUP = 5;
            int columnUP = 2;
            updateTablero[rowUP][columnUP] = 'X';
        }
        if (row == 3 && column == 2) {
            int rowUP = 5;
            int columnUP = 6;
            updateTablero[rowUP][columnUP] = 'X';
        }
        if (row == 3 && column == 3) {
            int rowUP = 5;
            int columnUP = 10;
            updateTablero[rowUP][columnUP] = 'X';
        }
    }
    else {
        if (row == 3 && column == 1) {
            int rowUP = 5;
            int columnUP = 2;
            updateTablero[rowUP][columnUP] = 'O';
        }
        if (row == 3 && column == 2) {
            int rowUP = 5;
            int columnUP = 6;
            updateTablero[rowUP][columnUP] = 'O';
        }
        if (row == 3 && column == 3) {
            int rowUP = 5;
            int columnUP = 10;
            updateTablero[rowUP][columnUP] = 'O';
        }
    }
   
}
