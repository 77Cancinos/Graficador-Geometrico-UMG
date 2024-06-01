#ifndef LINEA_H
#define LINEA_H

#include "Figura.h"
#include <string>

class Linea : public Figura {
private:
    int longitud;
    std::string orientacion;

public:
    Linea(int longitud, const std::string& orientacion) : longitud(longitud), orientacion(orientacion) {}
    void dibujar(int x, int y) override;
};

#endif // LINEA_H
