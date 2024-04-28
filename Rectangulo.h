#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Figura.h"

class Rectangulo : public Figura {
private:
    int ancho;
    int alto;
public:
    Rectangulo(int ancho, int alto) : ancho(ancho), alto(alto) {}
    void dibujar(int x, int y) override;
};

#endif // RECTANGULO_H
