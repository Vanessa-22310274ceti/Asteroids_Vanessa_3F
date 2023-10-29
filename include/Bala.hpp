#pragma once                    // para que no se duplique
#include <Dibujo.hpp>
#include <Actualizable.hpp>
using namespace std;

class Bala : public Dibujo, public Actualizable // Bala es un dibujo y un actualizable
{
private:
public:
    Bala(int x, int y) : Dibujo(x, y, "Bala")
    {
    }

    void DesplazarIzquierda()
    {
        this->x -= 1;
    }

    void DesplazarDerecha()
    {
        this->x += 1;
    }

    void DesplazarArrriba()
    {
        this->y -= 1;
    }

    void DesplazarAbajo()
    {
        this->y += 1;
    }

    void Actualizar()
    {
    }

    ~Bala() {}
};