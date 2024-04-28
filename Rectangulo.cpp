#include "Rectangulo.h"
#include <iostream>

void Rectangulo::dibujar(int x, int y) {
    for (int i = 0; i < alto; ++i) {
        for (int j = 0; j < ancho; ++j) {
            if (i == 0 || i == alto - 1 || j == 0 || j == ancho - 1) {
                std::cout << "* ";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}
