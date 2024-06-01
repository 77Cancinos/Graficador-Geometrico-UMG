#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Figura.h"
#include <string>

class Rectangulo : public Figura {
private:
    int ancho;
    int alto;
    std::string orientacion;
public:
    Rectangulo(int ancho, int alto, const std::string& orientacion) : ancho(ancho), alto(alto), orientacion(orientacion) {}
    void dibujar(int x, int y) override;
};

#endif // RECTANGULO_H
