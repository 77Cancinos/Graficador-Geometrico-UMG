#ifndef HEXAGONO_H
#define HEXAGONO_H

#include "Figura.h"
#include <string>

class Hexagono : public Figura {
private:
    int lado;
    std::string orientacion;

public:
    Hexagono(int lado, std::string orientacion) : lado(lado), orientacion(orientacion) {}
    void dibujar(int x, int y) override;
};

#endif // HEXAGONO_H
