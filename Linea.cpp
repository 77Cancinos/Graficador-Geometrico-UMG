#include "Linea.h"
#include <iostream>

extern char drawingCharacter;  // Variable global para el carácter de dibujo

void Linea::dibujar(int x, int y) {
    std::cout << "Dibujando línea de longitud " << longitud << " en orientación: " << orientacion << " desde (" << x << ", " << y << ")" << std::endl;

    for (int i = 0; i < longitud; i++) {
        std::cout << std::string(x, ' ') << drawingCharacter << std::endl;  // Usar el carácter global para dibujar

        if (orientacion == "Arriba") {
            y--;
        } else if (orientacion == "Abajo") {
            y++;
        } else if (orientacion == "Derecha") {
            x++;
        } else if (orientacion == "Izquierda") {
            x--;
        } else if (orientacion == "Diagonal Derecha Arriba") {
            x++;
            y--;
        } else if (orientacion == "Diagonal Derecha Abajo") {
            x++;
            y++;
        } else if (orientacion == "Diagonal Izquierda Arriba") {
            x--;
            y--;
        } else if (orientacion == "Diagonal Izquierda Abajo") {
            x--;
            y++;
        }

        // Asegurarse de que el cursor se mueva a la línea siguiente antes de dibujar de nuevo
        if (orientacion != "Derecha" && orientacion != "Izquierda") {
            std::cout << std::string(x, ' ');
        }
    }
    std::cout << std::endl;  // Terminar con una nueva línea
}
