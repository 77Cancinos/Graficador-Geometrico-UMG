#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"

class Triangulo : public Figura {
    int baseSize;
public:
    Triangulo(int baseSize) : baseSize(baseSize) {}
    void dibujar() override; // Implementación específica para dibujar un triángulo.
};

#endif
