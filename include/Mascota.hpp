#include <iostream>
#include <string>
#include <cstdio>

class Mascota
{
private:
    /* data */
    std::string nombre;

public:
    Mascota(/* args */)
    {
        std::cout << "Nueva mascota " << std::endl;
        this->nombre = "Firulais";
    }
    ~Mascota()
    {
        std::cout << "Adios " << std::endl;
    }

    void Inicializar()
    {
        std::cout << "Nueva mascota " << std::endl;
        this->nombre = "Firulais";
    }

    void Destruir()
    {
        std::cout << "Adios " << std::endl;
    }

    void DecirNombre()
    {
        std::cout << "Mi nombre es: " << this->nombre << std::endl;
    }

    void Comer()
    {
        std::cout << "Estoy comiendo" << std::endl;
    }
};