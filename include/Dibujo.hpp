#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <curses.h>

class Dibujo
{
private:
    std::fstream archivo;
    // data : atributos : implementacion oculta
protected:  // Las clases hijas pueden ver estas variables
    int x;
    int y;

public:
    Dibujo()
    {
        this->x = 0;
        this->y = 0;
    }
    Dibujo(int x, int y, std::string recurso)
    {
        // Inicializar
        archivo.open("./data/" + recurso + ".txt"); // Objeto para leer un archivo
        this->x = x;
        this->y = y;
    }

    Dibujo(std::string recurso)
    {
        // Inicializar
        archivo.open("./data/" + recurso + ".txt"); // Objeto para leer un archivo
        this->x = 0;
        this->y = 0;
    }

        // Dibujate
    void Dibujar()
    {
        // Proceso
        std::string linea;

        move(this->y, this->x);
        while (std::getline(archivo, linea))
        {
            int y = getcury(stdscr); // Ventana en la que estamos trabajando
            mvaddstr(
                y + 1,
                this->x,
                linea.c_str()); // Agregar cadena de texto dentro de la pantalla dibujada
        }
        archivo.clear();  // Limpiar variables
        archivo.seekg(0); // Mandar cursor al inicio
    }

    ~Dibujo()
    {
        // Finalizacion
        archivo.close(); // Liberar archivo
    }
};