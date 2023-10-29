#pragma once                                            // para que no se duplique
#include <Dibujo.hpp>
#include <Actualizable.hpp>

class ObjetoMovil : public Dibujo, public Actualizable // ObjetoMovil es un dibujo y un actualizable
{
private:
public:
    ObjetoMovil(/* args */) : Dibujo("Asteroids")
    {
    }

    ObjetoMovil(int x, int y, std::string recurso) : Dibujo(x, y, recurso)
    {
    }

    void DesplazarArrriba()
    {
        this->y -= 1;
        if (this->y == 0)
        {
            this->y = 100;
        }
    }

    void DesplazarAbajo()
    {
        this->y += 1;
        if (this->x == 100)
        {
            this->x = 0;
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

    void Actualizar()
    {
    }
    ~ObjetoMovil() {}
};