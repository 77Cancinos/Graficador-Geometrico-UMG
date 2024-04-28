#include "Triangulo.h"
#include <iostream>
#include <cmath>

void Triangulo::dibujar(int x, int y) {
    int altura = static_cast<int>((std::sqrt(3)/2) * baseSize);
    int espacios = baseSize / 2 + y;
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < espacios; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < i * 2 + 1; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
        espacios--;
    }
}
