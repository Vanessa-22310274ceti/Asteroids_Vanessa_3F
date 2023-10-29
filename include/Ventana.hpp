#include <curses.h>
#include <unistd.h>     // Libreria estandar del sistema unix
#include <list>
#include <Actualizable.hpp>
using namespace std;

class Ventana
{
private:
    /* data */
public:
    Ventana(/* args */)
    {
        initscr();       // Inicializar pantalla
        noecho();        // No eco en la pantalla
        curs_set(FALSE); // Ocultar cursor
        // ENTRADA DEL TECLADO:
        cbreak();
        keypad(stdscr, TRUE);
        timeout(10);
    }

    void Actualizar(list<Actualizable *> actualizables)
    {
        clear();
        for (auto &&actualizable : actualizables)
        {
            actualizable->Actualizar();
        }

        usleep(41000); // Delay 0.041s / fotograma   (24 img/seg)
    }

    void Dibujar(list<Dibujo *> dibujos)
    {
        clear();
        for (auto &&dibujo : dibujos)
        {
            dibujo->Dibujar(); // Aqui dibujar vaca
        }

        box(stdscr, '|', '='); // Pantalla estandar --> Dibujar caja en la pantalla
        refresh();             // Refrescar pantalla --> Pasar de la pantalla virtual al PC
    }

    ~Ventana()
    {
        keypad(stdscr, FALSE); // Liberar pantalla
        endwin();              // Finalizar pantalla
    }
};