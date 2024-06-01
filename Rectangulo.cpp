#include "Rectangulo.h"
#include <iostream>

extern char drawingCharacter;  // Variable global para el carácter de dibujo

void Rectangulo::dibujar(int x, int y) {
    std::cout << "Dibujando rectángulo de " << ancho << "x" << alto << " en orientación: " << orientacion << " desde (" << x << ", " << y << ")" << std::endl;
    if (orientacion == "Arriba") {
        y -= alto - 1;  // Ajustamos y para comenzar desde la esquina superior
    }

    for (int i = 0; i < alto; ++i) {
        std::cout << std::string(x, ' ');  // Respetar la posición en x
        for (int j = 0; j < ancho; ++j) {
            if (i == 0 || i == alto - 1 || j == 0 || j == ancho - 1) {
                std::cout << drawingCharacter << ' ';  // Usar el carácter de dibujo global
            } else {
                std::cout << "  ";  // Espacios para el interior del rectángulo
            }
        }
        std::cout << std::endl;
        if (orientacion == "Abajo") {
            y++;  // Incrementamos y en cada iteración para las siguientes líneas
        } else {
            y--;  // Decrementamos y para dibujar hacia arriba
        }
    }
}
