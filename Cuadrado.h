#ifndef CUADRADO_H
#define CUADRADO_H

#include "Figura.h"
#include <string>

class Cuadrado : public Figura {
private:
    int lado;
    std::string orientacion;
public:
    Cuadrado(int lado, const std::string& orientacion) : lado(lado), orientacion(orientacion) {}
    void dibujar(int x, int y) override;
};

#endif // CUADRADO_H
