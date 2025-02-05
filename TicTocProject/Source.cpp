#include <iostream>

#define xLength 7
#define yLength 13

int main() {
    char tablero[xLength][yLength];

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
