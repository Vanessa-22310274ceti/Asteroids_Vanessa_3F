#pragma once                                        // para que no se duplique
#include <Dibujo.hpp>
#include <Actualizable.hpp>

class Portada : public Dibujo, public Actualizable // Portada es un dibujo y un actualizable
{
private:
public:
    Portada(/* args */) : Dibujo("Asteroids")
    {
    }

    Portada(int x, int y) : Dibujo(x, y, "Logo")
    {
    }

    void Actualizar()
    {
        // this->x += 1;
        // this->y += 1;
    }

    ~Portada() {}
};