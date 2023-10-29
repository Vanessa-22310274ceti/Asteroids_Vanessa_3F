#pragma once // para que no se duplique
#include <Dibujo.hpp>
#include <Actualizable.hpp>

class Asteroide : public Dibujo, public Actualizable // Asteroide es un dibujo y un actualizable
{
private:
public:
    Asteroide(/* args */) : Dibujo("Asteroids")
    {
    }

    Asteroide(int x, int y, std::string recurso) : Dibujo(x, y, recurso)
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

    void DesplazarDiagonal()
    {
        this->x += 1;
        this->y += 1;

        if (this->x == 200)
        {
            this->x = 0;
        }
        if (this->y == 100)
        {
            this->y = 0;
        }
    }

    void Disparar()
    {
        // this->arma;
    }

    void Dividir()
    {
    }
    void Morir()
    {
    }

    ~Asteroide() {}
};
