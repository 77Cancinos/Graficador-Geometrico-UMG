#include <iostream>
#include <limits> // Añade esto para usar std::numeric_limits
#include <conio.h> // para _kbhit() y _getch() en Windows
#include "Figura.h"
#include "Triangulo.h"
// ... incluir otros archivos de cabecera ...

void mostrarMenu() {
    // Lógica para mostrar el menú
    std::cout << "\nSelecciona una figura para dibujar:" << std::endl;
    std::cout << "1. Triangulo" << std::endl;
    // ... agregar más figuras aquí ...
}

// Esta función asegura que el usuario ingrese un número válido para las dimensiones
int pedirDimension(const char* nombre) {
    int valor;
    std::cout << "Ingresa el tamaño de " << nombre << " del triángulo: ";
    while (!(std::cin >> valor) || valor <= 0) {
        std::cout << "Por favor, ingresa un valor positivo: ";
        std::cin.clear(); // limpiar el estado de fallo de cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignorar la entrada hasta la siguiente línea
    }
    return valor;
}

void limpiarPantalla() {
    // Esto es específico de Windows. En otros sistemas, podrías necesitar usar 'clear' en lugar de 'cls'
    system("cls");
}

int main() {
    bool isRunning = true;
    // Asumiendo que las coordenadas iniciales del cursor son (0,0)
    int cursorX = 0, cursorY = 0;

    std::cout << "Presiona 'F' para empezar..." << std::endl;

    while (isRunning) {
        if (_kbhit()) {
            char key = _getch();
            switch (key) {
                case 'w': // Mover cursor hacia arriba
                    cursorY--;
                    break;
                case 's': // Mover cursor hacia abajo
                    cursorY++;
                    break;
                case 'a': // Mover cursor a la izquierda
                    cursorX--;
                    break;
                case 'd': // Mover cursor a la derecha
                    cursorX++;
                    break;
                case 'f': // Usamos 'f' como sustituto para F12 por simplicidad
                    mostrarMenu();
                    int opcion;
                    std::cin >> opcion; // Espera la entrada del usuario
                    if (opcion == 1) {
                        int base = pedirDimension("la base"); // Pedir al usuario la base del triángulo
                        // Suponiendo que la función dibujar() toma la base como parámetro
                        Triangulo triangulo(base);
                        triangulo.dibujar();
                    }
                    // ... manejo de otras figuras ...
                    break;
                case 27: // ESC para salir
                    isRunning = false;
                    break;
                default:
                    break;
            }
        }
        // Aquí puedes agregar la lógica para limpiar y actualizar la pantalla.
    }
    return 0;
}

