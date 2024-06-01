#include "Hexagono.h"
#include <iostream>

extern char drawingCharacter;  // Variable global para el carácter de dibujo

void Hexagono::dibujar(int x, int y) {
    std::cout << "Dibujando hexágono de lado " << lado << " en orientación: " << orientacion << std::endl;
    if (orientacion == "Horizontal") {
        int n = lado;
        int m = (2 * n) - 1;  // Ancho máximo en el centro del hexágono
        // Parte superior del hexágono
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j >= (n - 1 - i) && j < (n - 1 - i + 2 * i + 1))
                    std::cout << drawingCharacter;
                else
                    std::cout << " ";
            }
            std::cout << std::endl;
        }
        // Parte inferior del hexágono
        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < m; j++) {
                if (j >= (n - 1 - i) && j < (n - 1 - i + 2 * i + 1))
                    std::cout << drawingCharacter;
                else
                    std::cout << " ";
            }
            std::cout << std::endl;
        }
    } else if (orientacion == "Vertical") {
        int n = lado;
        int height = 2 * n - 1;
        for (int i = -n + 1; i < n; i++) {
            for (int j = 0; j < height; j++) {
                int dx = abs(i);
                if (j >= dx && j < height - dx)
                    std::cout << drawingCharacter;
                else
                    std::cout << " ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "Orientación no soportada." << std::endl;
    }
}
