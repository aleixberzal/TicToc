#pragma once

#include <iostream>

#define xLength 7
#define yLength 13

void gamePlay(char updateTablero[xLength][yLength], int& row, int& column, int& rowUP, int& columnUP);
void firstRow(char updateTablero[xLength][yLength], int& row, int& column, int& rowUP, int& columnUP);
void secondRow(char updateTablero[xLength][yLength], int& row, int& column, int& rowUP, int& columnUP);
void thirdRow(char updateTablero[xLength][yLength], int& row, int& column, int& rowUP, int& columnUP);

