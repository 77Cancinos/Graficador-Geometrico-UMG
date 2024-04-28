#ifndef CUADRADO_H
#define CUADRADO_H

#include "Figura.h"

class Cuadrado : public Figura {
private:
    int lado;
public:
    Cuadrado(int lado) : lado(lado) {}
    void dibujar(int x, int y) override;
};

#endif // CUADRADO_H
