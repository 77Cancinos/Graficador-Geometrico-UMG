#include "Rombo.h"
#include <iostream>

extern char drawingCharacter;  // Variable global para el car�cter de dibujo

void Rombo::dibujar(int x, int y) {
    std::cout << "Dibujando rombo de lado " << lado << " en orientaci�n: " << orientacion << " desde (" << x << ", " << y << ")" << std::endl;
    int n = lado;
    int mid = (n / 2);

    if (orientacion == "Arriba" || orientacion == "Abajo") {
        // Ajusta el inicio en y dependiendo de la orientaci�n
        int startLine = (orientacion == "Arriba") ? y - mid : y;

        for (int i = 0; i < mid; ++i) {
            std::cout << std::string(x + mid - i, ' ');
            for (int j = 0; j < 2 * i + 1; ++j) {
                std::cout << drawingCharacter;
            }
            std::cout << std::endl;
        }
        for (int i = mid; i >= 0; --i) {
            std::cout << std::string(x + mid - i, ' ');
            for (int j = 0; j < 2 * i + 1; ++j) {
                std::cout << drawingCharacter;
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "Orientaci�n no soportada a�n." << std::endl;
    }
}
