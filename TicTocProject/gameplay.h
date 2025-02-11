#pragma once 
#include <iostream>

#define xLength 7
#define yLength 13
void gamePlay(char tablero[xLength][yLength], int& row, int& column, bool& turno1);
void newGame(char tablero[xLength][yLength], int& row, int& column, bool& turno1, bool& victory);
void loadGame(char tablero[xLength][yLength], int& row, int& column, bool& turno1, bool& gameOver);
void exitGame();
bool victoryLogic();
