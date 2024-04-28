#ifndef FIGURA_H
#define FIGURA_H

class Figura {
public:
    virtual void dibujar() = 0; // Función puramente virtual.
    virtual ~Figura() {} // Destructor virtual necesario para una clase base con métodos virtuales.
};

#endif
