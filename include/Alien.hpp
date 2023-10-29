#pragma once // para que no se duplique
#include <Dibujo.hpp>
#include <Actualizable.hpp>

class Alien : public Dibujo, public Actualizable // Alien es un dibujo y un actualizable
{
private:
public:
    Alien(/* args */) : Dibujo("Asteroids")
    {
    }

    Alien(int x, int y) : Dibujo(x, y, "Alien")
    {
    }

    void Actualizar()
    {
        // this->x += 1;
        // this->y += 1;
    }

    void DesplazarArrriba()
    {
        this->y -= 1;
        if (this->y == 0)
        {
            this->y = 200;
        }
    }

    void DesplazarAbajo()
    {
        this->y += 1;
        if (this->y == 100)
        {
            this->y = 0;
        }
    }

    void DesplazarIzquierda()
    {
        this->x -= 1;
        if (this->x == 0)
        {
            this->x = 200;
        }
    }

    void DesplazarDerecha()
    {
        this->x += 1;
        if (this->x == 200)
        {
            this->x = 0;
        }
    }

    void Disparar()
    {
    }
    void Morir()
    {
    }

    ~Alien() {}
};