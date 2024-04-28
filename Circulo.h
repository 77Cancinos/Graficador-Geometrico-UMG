#ifndef CIRCULO_H
#define CIRCULO_H

#include "Figura.h"

class Circulo : public Figura {
private:
    int radio;
public:
    Circulo(int radio) : radio(radio) {}
    void dibujar(int x, int y) override;
};

#endif // CIRCULO_H
