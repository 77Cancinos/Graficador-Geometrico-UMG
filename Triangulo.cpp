#include "Triangulo.h"
#include <iostream>
#include <cmath>

extern char drawingCharacter; // Usar la variable global

void Triangulo::dibujar(int x, int y) {
    std::cout << "Dibujando triángulo en orientación: " << orientacion << " desde (" << x << ", " << y << ")" << std::endl;
    int altura = static_cast<int>((std::sqrt(3) / 2) * baseSize);

    if (orientacion == "Arriba") {
        for (int i = 0; i < altura; ++i) {
            for (int j = 0; j < baseSize - i; ++j) {
                std::cout << " ";
            }
            for (int j = 0; j < 2 * i + 1; ++j) {
                std::cout << drawingCharacter;
            }
            std::cout << std::endl;
        }
    } else if (orientacion == "Abajo") {
        for (int i = altura - 1; i >= 0; --i) {
            for (int j = 0; j < baseSize - i; ++j) {
                std::cout << " ";
            }
            for (int j = 0; j < 2 * i + 1; ++j) {
                std::cout << drawingCharacter;
            }
            std::cout << std::endl;
        }
    } else if (orientacion == "Derecha" || orientacion == "Izquierda") {
        // La lógica para estas orientaciones debe ser revisada y adaptada según las necesidades gráficas
        // El código original no era claro para las orientaciones de derecha e izquierda
        std::cout << "Orientación '" << orientacion << "' no implementada correctamente.\n";
    }
}
