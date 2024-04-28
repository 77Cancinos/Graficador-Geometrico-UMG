#ifndef TRIANGULO_H
#define TRIANGULO_H

#include "Figura.h"

class Triangulo : public Figura {
private:
    int baseSize;
public:
    Triangulo(int baseSize) : baseSize(baseSize) {}
    void dibujar(int x, int y) override;
};

#endif // TRIANGULO_H
