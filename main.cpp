#include <iostream>
#include <limits> // A�ade esto para usar std::numeric_limits
#include <conio.h> // para _kbhit() y _getch() en Windows
#include "Figura.h"
#include "Triangulo.h"
// ... incluir otros archivos de cabecera ...

void mostrarMenu() {
    // L�gica para mostrar el men�
    std::cout << "\nSelecciona una figura para dibujar:" << std::endl;
    std::cout << "1. Triangulo" << std::endl;
    // ... agregar m�s figuras aqu� ...
}

// Esta funci�n asegura que el usuario ingrese un n�mero v�lido para las dimensiones
int pedirDimension(const char* nombre) {
    int valor;
    std::cout << "Ingresa el tama�o de " << nombre << " del tri�ngulo: ";
    while (!(std::cin >> valor) || valor <= 0) {
        std::cout << "Por favor, ingresa un valor positivo: ";
        std::cin.clear(); // limpiar el estado de fallo de cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignorar la entrada hasta la siguiente l�nea
    }
    return valor;
}

void limpiarPantalla() {
    // Esto es espec�fico de Windows. En otros sistemas, podr�as necesitar usar 'clear' en lugar de 'cls'
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
                        int base = pedirDimension("la base"); // Pedir al usuario la base del tri�ngulo
                        // Suponiendo que la funci�n dibujar() toma la base como par�metro
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
        // Aqu� puedes agregar la l�gica para limpiar y actualizar la pantalla.
    }
    return 0;
}

