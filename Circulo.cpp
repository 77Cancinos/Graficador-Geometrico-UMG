#include "Circulo.h"
#include <iostream>
#include <cmath>

extern char drawingCharacter; // Accede a la variable global definida en main.cpp

void Circulo::dibujar(int cx, int cy) {
    for (int y = -radio; y <= radio; y++) {
        for (int x = -radio; x <= radio; x++) {
            if (std::pow(x, 2) + std::pow(y, 2) <= std::pow(radio, 2)) {
                std::cout << drawingCharacter << " ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}
