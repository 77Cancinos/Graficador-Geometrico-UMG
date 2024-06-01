#include <iostream>
#include <conio.h>
#include <limits>
#include "Figura.h"
#include "Triangulo.h"
#include "Cuadrado.h"
#include "Rectangulo.h"
#include "Circulo.h"
#include "Linea.h"
#include "Rombo.h"
#include "Hexagono.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <string>

char drawingCharacter = '*';  // Carácter inicial para dibujar
// Variable global para mantener el handle de la consola
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void cambiarColor(int color) {
    SetConsoleTextAttribute(hConsole, color);
}

void mostrarMenu() {
    std::cout << "\nSelecciona una figura para dibujar:" << std::endl;
    std::cout << "1. Triangulo" << std::endl;
    std::cout << "2. Cuadrado" << std::endl;
    std::cout << "3. Rectangulo" << std::endl;
    std::cout << "4. Circulo" << std::endl;
    std::cout << "5. Linea" << std::endl;
    std::cout << "6. Rombo" << std::endl;
    std::cout << "7. Hexagono" << std::endl;
    std::cout << "8. Nuevo Caracter" << std::endl;
    std::cout << "9. Limpiar Pantalla" << std::endl;
    std::cout << "10. Color de Caracter" << std::endl;
    std::cout << "11. Grabar Pantalla" << std::endl;
    std::cout << "12. Abrir archivo y mostrar en pantalla" << std::endl;
    std::cout << "0. Salir" << std::endl;
}

void mostrarMenuColor() {
    std::cout << "Selecciona un color para los caracteres:" << std::endl;
    std::cout << " 0 - Negro" << std::endl;
    std::cout << " 1 - Azul oscuro" << std::endl;
    std::cout << " 2 - Verde oscuro" << std::endl;
    std::cout << " 3 - Aguamarina" << std::endl;
    std::cout << " 4 - Rojo oscuro" << std::endl;
    std::cout << " 5 - Púrpura" << std::endl;
    std::cout << " 6 - Amarillo oscuro (ocre)" << std::endl;
    std::cout << " 7 - Gris claro" << std::endl;
    std::cout << " 8 - Gris oscuro" << std::endl;
    std::cout << " 9 - Azul brillante" << std::endl;
    std::cout << "10 - Verde brillante" << std::endl;
    std::cout << "11 - Aguamarina brillante" << std::endl;
    std::cout << "12 - Rojo brillante" << std::endl;
    std::cout << "13 - Rosa brillante" << std::endl;
    std::cout << "14 - Amarillo brillante" << std::endl;
    std::cout << "15 - Blanco" << std::endl;
    std::cout << "Ingresa el número del color deseado: ";
}

void guardarPantalla(const std::string& filename) {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    int columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    COORD topLeft = {0, 0};
    DWORD cCharsWritten;
    std::string buffer(columns * rows, ' ');

    // Leer los caracteres en el buffer actual
    ReadConsoleOutputCharacter(hConsole, &buffer[0], columns * rows, topLeft, &cCharsWritten);

    // Guardar el contenido en un archivo
    std::ofstream file(filename);
    int pos = 0;
    for (int r = 0; r < rows; ++r) {
        file.write(&buffer[pos], columns);
        file.put('\n');  // Nueva línea después de cada fila
        pos += columns;
    }
    file.close();
}


void mostrarContenidoArchivo(const std::string& rutaArchivo) {
    std::ifstream archivo(rutaArchivo);
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo: " << rutaArchivo << std::endl;
        return;
    }

    std::string linea;
    while (getline(archivo, linea)) {
        std::cout << linea << std::endl;
    }
    archivo.close();
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
                case 'f':
                    limpiarPantalla();
                    mostrarMenu();
                    int opcion;
                    std::cin >> opcion;
                    if (opcion == 1) {
                        int base = pedirDimension("la base");
                        std::cout << "Ingresa la orientación (Arriba, Abajo, Derecha, Izquierda): ";
                        std::string orientacion;
                        std::cin >> orientacion;
                        Triangulo triangulo(base, orientacion);
                        triangulo.dibujar(cursorX, cursorY);
                    } else if (opcion == 2) {
                        int lado = pedirDimension("el lado");
                        std::cout << "Ingresa la orientación (Arriba, Abajo, Derecha, Izquierda): ";
                        std::string orientacion;
                        std::cin >> orientacion;
                        Cuadrado cuadrado(lado, orientacion);
                        cuadrado.dibujar(cursorX, cursorY);
                    } else if (opcion == 3) {
                        int ancho = pedirDimension("el ancho");
                        int alto = pedirDimension("la altura");
                        std::cout << "Ingresa la orientación (Arriba, Abajo): ";
                        std::string orientacion;
                        std::cin >> orientacion;
                        Rectangulo rectangulo(ancho, alto, orientacion);
                        rectangulo.dibujar(cursorX, cursorY);
                    } else if (opcion == 4) {
                        int radio = pedirDimension("el radio");
                        Circulo circulo(radio);
                        circulo.dibujar(cursorX, cursorY);
                    } else if (opcion == 5) {
                         int longitud = pedirDimension("la longitud");
                        std::cout << "Selecciona la orientación (Arriba, Abajo, Derecha, Izquierda, "
                                  << "Diagonal Derecha Arriba, Diagonal Derecha Abajo, "
                                  << "Diagonal Izquierda Arriba, Diagonal Izquierda Abajo): ";
                        std::string orientacion;
                        std::cin >> orientacion;
                        Linea linea(longitud, orientacion);
                        linea.dibujar(cursorX, cursorY);
                    } else if (opcion == 6) {
                         int lado = pedirDimension("el lado del rombo");
                         std::cout << "Selecciona la orientación (Arriba, Abajo): ";
                         std::string orientacion;
                         std::cin >> orientacion;
                         Rombo rombo(lado, orientacion);
                         rombo.dibujar(cursorX, cursorY);
                    } else if (opcion == 7) {
                         int lado = pedirDimension("el lado del hexágono");
                         std::cout << "Selecciona la orientación (Vertical, Horizontal): ";
                         std::string orientacion;
                         std::cin >> orientacion;
                         Hexagono hexagono(lado, orientacion);
                         hexagono.dibujar(cursorX, cursorY);
                    } else if (opcion == 8) {
                         std::cout << "Ingresa el nuevo carácter para dibujar: ";
                         std::cin >> drawingCharacter;
                    } else if (opcion == 9) {
                        limpiarPantalla();
                    } else if (opcion == 10) {
                         std::cout << "Ingresa el código de color (0-15): ";
                         int color;
                         mostrarMenuColor();
                         std::cin >> color;
                         if (color >= 0 && color <= 15) {
                            cambiarColor(color);
                            std::cout << "Color cambiado exitosamente!" << std::endl;
                         } else {
                            std::cout << "Color no válido, por favor ingresa un número entre 0 y 15." << std::endl;
                         }
                    } else if (opcion == 11) {
                        std::cout << "Ingrese el nombre del archivo para guardar la pantalla: ";
                        std::string filename;
                        std::cin.ignore(); // Ignora el '\n' que puede estar en el buffer
                        std::getline(std::cin, filename);
                        guardarPantalla(filename);
                        std::cout << "Pantalla guardada en '" << filename << "'" << std::endl;
                    } else if (opcion == 12) {
                        std::cout << "Ingrese la ruta del archivo a abrir: ";
                        std::string rutaArchivo;
                        std::cin.ignore();
                        std::getline(std::cin, rutaArchivo);
                        mostrarContenidoArchivo(rutaArchivo);
                    } else if (opcion == 0) {
                        isRunning = false;
                    }
                    std::cout << "Presiona cualquier tecla para volver al menú..." << std::endl;
                    _getch();
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
