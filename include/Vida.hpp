#include <iostream>
#include <string>
#include <cstdio>

class Vida
{
private:
    int vidas = 3;

public:
    Vida(/* args */) {}
    ~Vida() {}
    void PerderVida()
    {
        vidas = vidas - 1;
    }
};