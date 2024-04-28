#include <iostream>
#include <conio.h>
#include <limits>
#include "Figura.h"
#include "Triangulo.h"
#include "Cuadrado.h"
#include "Rectangulo.h"
#include "Circulo.h"


void mostrarMenu() {
    std::cout << "\nSelecciona una figura para dibujar:" << std::endl;
    std::cout << "1. Triangulo" << std::endl;
    std::cout << "2. Cuadrado" << std::endl;
    std::cout << "3. Rectangulo" << std::endl;
    std::cout << "4. Circulo" << std::endl;
}

int pedirDimension(const char* nombre) {
    int valor;
    std::cout << "Ingresa el tamaño de " << nombre << " de la figura: ";
    while (!(std::cin >> valor) || valor <= 0) {
        std::cout << "Por favor, ingresa un valor positivo: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return valor;
}

void limpiarPantalla() {
    system("cls");
}

int main() {
    bool isRunning = true;
    int cursorX = 0, cursorY = 0;

    std::cout << "Presiona 'F' para empezar..." << std::endl;

    while (isRunning) {
        if (_kbhit()) {
            char key = _getch();
            switch (key) {
                // ... (tus casos de teclas para mover el cursor)
                case 'f': // Usamos 'f' como sustituto para F12 por simplicidad
                    while (true) {
                        limpiarPantalla(); // Limpia la pantalla para mostrar el menú
                        mostrarMenu();
                        int opcion;
                        std::cin >> opcion; // Espera la entrada del usuario
                        if (opcion == 1) {
                            int base = pedirDimension("la base");
                            Triangulo triangulo(base);
                            triangulo.dibujar(cursorX, cursorY);
                        } else if (opcion == 2) {
                            int lado = pedirDimension("el lado");
                            Cuadrado cuadrado(lado);
                            cuadrado.dibujar(cursorX, cursorY);
                        } else if (opcion == 3) {
                            int ancho = pedirDimension("el ancho");
                            int alto = pedirDimension("la altura");
                            Rectangulo rectangulo(ancho, alto);
                            rectangulo.dibujar(cursorX, cursorY);
                        } else if (opcion == 4) {
                            int radio = pedirDimension("el radio");
                            Circulo circulo(radio);
                            circulo.dibujar(cursorX, cursorY);
                        } else if (opcion == 0) {
                            // Supongamos que la opción 0 es para salir del menú
                            break;
                        }
                        // Podrías agregar un pequeño "sleep" aquí para que el dibujo se muestre antes de limpiar la pantalla.
                        std::cout << "Presiona cualquier tecla para volver al menú..." << std::endl;
                        _getch(); // Espera a que el usuario presione una tecla antes de volver al menú
                    }
                    break;
                case 27: // ESC para salir
                    isRunning = false;
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}
