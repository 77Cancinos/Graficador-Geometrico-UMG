#ifndef FIGURA_H
#define FIGURA_H

class Figura {
public:
    virtual void dibujar(int x, int y) = 0;
    virtual ~Figura() {}
};

#endif // FIGURA_H
