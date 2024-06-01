#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"
#include <string> // Asegúrate de incluir la biblioteca string

class Triangulo : public Figura {
private:
    int baseSize;
    std::string orientacion; // Añade orientación como atributo
public:
    Triangulo(int baseSize, std::string orientacion) : baseSize(baseSize), orientacion(orientacion) {}
    void dibujar(int x, int y) override;
};

#endif // TRIANGULO_H
