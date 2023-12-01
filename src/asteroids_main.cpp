#include <Dibujo.hpp>
#include <Ventana.hpp>
#include <list>
#include <curses.h>
#include <Asteroide.hpp>
#include <Nave.hpp>
#include <Alien.hpp>
#include <Portada.hpp>
#include <Bala.hpp>
#include <ObjetoMovil.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
    
    Ventana ventana;
    
    

    

    Asteroide* asteroide1 = new Asteroide(0, 0,"AsteroideGrande");
    Asteroide* asteroide2 = new Asteroide(100, 0,"AsteroideMediano");
    Asteroide* asteroide3 = new Asteroide(50, 50,"AsteroideChico");
    Asteroide* asteroide4 = new Asteroide(50, 0,"AsteroideChico");
    Asteroide* asteroide5 = new Asteroide(0, 80,"AsteroideMediano");
    Asteroide* asteroide6 = new Asteroide(100, 100,"AsteroideGrande");

    Nave* nave = new Nave(0,0);
    Alien* alien = new Alien(0,14);
    Portada* portada = new Portada(45,5);
    //Arma* arma = new Arma();
    Bala* bala = new Bala(0,2);
    Bala* bala2 = new Bala(2,2);

    //vaca1->RecogerArma(arma);

    list<Dibujo*> dibujos;
    dibujos.push_back(portada);
    dibujos.push_back(asteroide1);
    dibujos.push_back(asteroide2);
    dibujos.push_back(asteroide3);
    dibujos.push_back(asteroide4);
    dibujos.push_back(asteroide5);
    dibujos.push_back(asteroide6);
    dibujos.push_back(nave);
    dibujos.push_back(alien);
    dibujos.push_back(bala);
    dibujos.push_back(bala2);

    //list<ObjetoMovil*> objetosMoviles;
    //objetosMoviles.push_back(bala);

    list<Actualizable*> actualizables;
    actualizables.push_back(portada);
    actualizables.push_back(asteroide1);
    actualizables.push_back(asteroide2);
    actualizables.push_back(asteroide3);
    actualizables.push_back(asteroide4);
    actualizables.push_back(asteroide5);
    actualizables.push_back(asteroide6);
    actualizables.push_back(nave);
    actualizables.push_back(alien);
    actualizables.push_back(bala);
    actualizables.push_back(bala);

    while (true)
    {


        

 
        
        
        asteroide1->DesplazarDiagonal();
        asteroide2->DesplazarDerecha();
        asteroide3->DesplazarIzquierda();
        asteroide4->DesplazarDiagonal();
        asteroide5->DesplazarAbajo();
        asteroide6->DesplazarArrriba();
        alien->DesplazarDerecha();
        //nave->Disparar();
        bala->DesplazarDerecha();
        alien->DesplazarDerecha();
       


        char key = getch();


        




        if (key == 'q' || key =='Q')
        {
            // Salir del juego
            break;
        }

        if (key == 'j' || key == KEY_LEFT) // Mover a la izquierda
        {
            nave->DesplazarIzquierda();
        }
        if (key == 'l' || key == KEY_RIGHT) // Mover a la derecha
        {
            nave->DesplazarDerecha();
        }
        if (key == 'i')                     // Mover arriba
        {
            nave->DesplazarArrriba();
        }
        if (key == 'm')                     // Mover abajo
        {
            nave->DesplazarAbajo();
        }

        // Disparar derech, izquierda, arriba y abajo
        


        if (key == ' ')
        {
            bala2->DesplazarDerecha();
        }
        
        

        ventana.Actualizar(actualizables);
        ventana.Dibujar(dibujos);
    }

    //
    // Dibujo vaca2("VacaParada");
    // Dibujo vaca3("VacaSaltando");

    // vaca1.Dibujar();
    // vaca2.Dibujar();
    // vaca3.Dibujar();

    return 0;
}