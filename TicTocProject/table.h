#pragma once
#include <iostream>
#define xLength 7
#define yLength 13

void updateTable(char tablero[xLength][yLength], int& row, int& column, bool& turno1, bool& victory);
	void printTable(char tablero[xLength][yLength]);
	void createTable(char tablero[xLength][yLength]);
