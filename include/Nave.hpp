#pragma once                                    // para que no se duplique
#include <Dibujo.hpp>
#include <Actualizable.hpp>
#include <Bala.hpp>

class Nave : public Dibujo, public Actualizable // Nave es un dibujo y un actualizable
{
private:
public:
    Nave(/* args */) : Dibujo("Asteroids")
    {
    }

    Nave(int x, int y) : Dibujo(x, y, "NaveDerecha")
    {
    }

    void Actualizar()
    {
        // this->x += 1;
        // this->y += 1;
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

    void Disparar()
    {
    }
    
    void Morir()
    {
    }

    ~Nave() {}
};