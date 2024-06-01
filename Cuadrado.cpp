#include "Cuadrado.h"
#include <iostream>

extern char drawingCharacter; // Usar la variable global para el carácter de dibujo

void Cuadrado::dibujar(int x, int y) {
    std::cout << "Dibujando cuadrado en orientación: " << orientacion << " desde (" << x << ", " << y << ")" << std::endl;
    if (orientacion == "Derecha" || orientacion == "Izquierda") {
        int startX = (orientacion == "Izquierda") ? x - lado + 1 : x;  // Ajuste para izquierda
        for (int i = 0; i < lado; ++i) {
            for (int j = 0; j < lado; ++j) {
                if (i == 0 || i == lado - 1 || j == 0 || j == lado - 1) {
                    std::cout << std::string((orientacion == "Izquierda" ? x - j : x + j), ' ') << drawingCharacter;
                }
            }
            std::cout << std::endl;
            y++;  // Mover hacia abajo después de cada fila
        }
    } else {  // Orientación Arriba o Abajo
        int startY = (orientacion == "Arriba") ? y - lado + 1 : y;
        for (int i = 0; i < lado; ++i) {
            std::cout << std::string(x, ' ');
            for (int j = 0; j < lado; ++j) {
                if (i == 0 || i == lado - 1 || j == 0 || j == lado - 1) {
                    std::cout << drawingCharacter << ' ';
                }
            }
            std::cout << std::endl;
            startY++;  // Avanzar a la siguiente línea
        }
    }
}
