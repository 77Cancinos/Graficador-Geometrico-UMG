#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"

class Triangulo : public Figura {
    int baseSize;
public:
    Triangulo(int baseSize) : baseSize(baseSize) {}
    void dibujar() override; // Implementaci�n espec�fica para dibujar un tri�ngulo.
};

#endif
