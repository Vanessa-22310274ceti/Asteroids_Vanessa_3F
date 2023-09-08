#include <iostream>
#include <Mascota.hpp>

int main(int argc, char const *argv[])
{

    std::cout << "Tipos de datos" << std::endl;
    // Mascota m1; // Objetos de clase mascota
    // Mascota m2;

    // m1.Comer();
    // m2.Comer();

    std::cout << "int " << sizeof(int) << std::endl;
    std::cout << "char " << sizeof(char) << std::endl;
    std::cout << "bool " << sizeof(bool) << std::endl;
    std::cout << "float " << sizeof(float) << std::endl;
    std::cout << "double " << sizeof(double) << std::endl;
    std::cout << "Mascota " << sizeof(Mascota) << std::endl;

    std::cout << "\n\nDirecciones de memoria" << std::endl;
    int a = 4;
    std::cout << "Tamaño: " << sizeof(a) << std::endl;
    std::cout << "Contenido: " << a << std::endl;
    std::cout << "Direccion: " << &a << std::endl;

    void *puntero = malloc(32); // m - memoria  alloc - alocacion(reservar memoria)
    std::cout << "\n\nTamaño Puntero: " << sizeof(puntero) << std::endl;
    std::cout << "Puntero1: " << puntero << std::endl;
    std::cout << "Puntero2: " << &puntero << std::endl;

    free(puntero); // Liberar memoria

    // C - Memoria dinamica ----------------------------------
    std::cout << "\n\nMascota en C: " << std::endl;
    Mascota *mascotaC = (Mascota *)malloc(sizeof(Mascota));
    mascotaC->Inicializar();
    mascotaC->DecirNombre();
    mascotaC->Destruir();
    free(mascotaC);

    // C++ ---------------------------------------------------
    std::cout << "\n\nMascota en C++: " << std::endl;
    Mascota *mascotaCPP = new Mascota();
    mascotaCPP->DecirNombre();

    delete mascotaCPP;

    return 0;
}
