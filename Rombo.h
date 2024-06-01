#ifndef ROMBO_H
#define ROMBO_H

#include "Figura.h"
#include <string>

class Rombo : public Figura {
private:
    int lado;
    std::string orientacion;

public:
    Rombo(int lado, const std::string& orientacion) : lado(lado), orientacion(orientacion) {}
    void dibujar(int x, int y) override;
};

#endif // ROMBO_H
