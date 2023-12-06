#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Imagen.hpp>
#include <Personaje.hpp>
#include <Enemigo.hpp>
#include <Bala.hpp>
#include <Vida.hpp>

int main()
{
    int i = 0;                 // Indice de la matriz de balas
    int i2 = 0;                // Indice del for
    bool teclaEspacio = false; // Para que no se dispare la bala varias veces mientras se mantiene presionada la tecla
    int a[20] = {0};           // Direccion en x de la bala
    int b[20] = {0};           // Direccion en y de la bala
    int aleatorio = 0;         // Numero aleatorio para la posicion inicial del alien

    sf::RenderWindow window(sf::VideoMode(1000, 800), "Asteroids"); // Crear ventana

    // Cargar la fuente de texto TTF
    sf::Font font;
    if (!font.loadFromFile("./assets/fonts/Ring.ttf"))
    {
        // Manejar el error si no se puede cargar la fuente
        return -1;
    }
    // Crear un objeto de texto
    sf::Text score;
    score.setFont(font);
    score.setCharacterSize(29);
    score.setFillColor(sf::Color::White);
    score.setPosition(395, 0);
    score.setString("score ");

    Vida vida1 = Vida(sf::Vector2f(0, 0), "Vida");   // Imagen de la vida 1
    Vida vida2 = Vida(sf::Vector2f(50, 0), "Vida");  // Imagen de la vida 2
    Vida vida3 = Vida(sf::Vector2f(100, 0), "Vida"); // Imagen de la vida 3

    Enemigo asteroides[6] = {
        {Enemigo(sf::Vector2f(1000, 150), "AsteroideGrande")},
        {Enemigo(sf::Vector2f(-200, 580), "AsteroideChico")},
        {Enemigo(sf::Vector2f(650, 1000), "AsteroideChico")},
        {Enemigo(sf::Vector2f(70, -150), "AsteroideGrande")},
        {Enemigo(sf::Vector2f(-300, -300), "AsteroideGrande")},
        {Enemigo(sf::Vector2f(0, 600), "AsteroideGrande")}};

    Enemigo alien = Enemigo(sf::Vector2f(-300, 300), "Alien"); // Posicion inicial del alien
    alien.velocidad = 0.2;                                     // Velocidad del alien

    Bala balas[20] = {// Matriz de balas (solo se pueden usar 20 balas a la vez)
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")},
                      {Bala(sf::Vector2f(-4000, -3000), "Bala")}};

    Personaje nave(sf::Vector2f(350, 250), "Nave"); // Posicion inicial de la nave
    nave.velocidad = 0.2;                           // Velocidad de la nave

    while (window.isOpen()) // Mientras la ventana esté abierta
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // ------------------------------------------------ Asteroides moviendose aleatoriamente

        asteroides[0].move(asteroides[0].velocidad * -1, 0);                         // Mover en -x el asteroide 1
        asteroides[1].move(asteroides[1].velocidad, 0);                              // Mover en x el asteroide 2
        asteroides[2].move(0, asteroides[2].velocidad * -1);                         // Mover en -y el asteroide 3
        asteroides[3].move(0, asteroides[3].velocidad);                              // Mover en y el asteroide 4
        asteroides[4].move(asteroides[4].velocidad, asteroides[4].velocidad);        // Mover en x y en y el asteroide 5
        asteroides[5].move(asteroides[5].velocidad, asteroides[5].velocidad * -0.5); // Mover en -x y en -y el asteroide 6
        alien.move(alien.velocidad, 0);                                              // Mover en x el alien

        if (asteroides[0].getPosition().x < -150) // Si el asteroide sale de la pantalla por la izquierda...
        {
            aleatorio = std::rand() % 1001;                           // Generar un numero aleatorio entre 0 y 1000
            asteroides[0].setPosition(sf::Vector2f(1000, aleatorio)); // Posicion inicial del asteroide
            asteroides[0].velocidad = asteroides[0].velocidad + 0.01; // Aumentar la velocidad del asteroide
        }
        if (asteroides[1].getPosition().x > 1000) // Si el asteroide sale de la pantalla por la derecha...
        {
            aleatorio = std::rand() % 1001;                           // Generar un numero aleatorio entre 0 y 1000
            asteroides[1].setPosition(sf::Vector2f(-200, aleatorio)); // Posicion inicial del asteroide
            asteroides[1].velocidad = asteroides[1].velocidad + 0.01; // Aumentar la velocidad del asteroide
        }
        if (asteroides[2].getPosition().y < -150) // Si el asteroide sale de la pantalla por arriba...
        {
            aleatorio = std::rand() % 1001;                           // Generar un numero aleatorio entre 0 y 1000
            asteroides[2].setPosition(sf::Vector2f(aleatorio, 1000)); // Posicion inicial del asteroide
            asteroides[2].velocidad = asteroides[2].velocidad + 0.01; // Aumentar la velocidad del asteroide
        }
        if (asteroides[3].getPosition().y > 800) // Si el asteroide sale de la pantalla por abajo...
        {
            aleatorio = std::rand() % 1001;                           // Generar un numero aleatorio entre 0 y 1000
            asteroides[3].setPosition(sf::Vector2f(aleatorio, -150)); // Posicion inicial del asteroide
            asteroides[3].velocidad = asteroides[3].velocidad + 0.01; // Aumentar la velocidad del asteroide
        }
        if (asteroides[4].getPosition().x > 1000 || asteroides[4].getPosition().y > 800) // Si el asteroide sale de la pantalla por la derecha o por abajo...
        {
            aleatorio = std::rand() % 1001;                            // Generar un numero aleatorio entre 0 y 1000
            asteroides[4].setPosition(sf::Vector2f(-300, -aleatorio)); // Posicion inicial del asteroide
            asteroides[4].velocidad = asteroides[4].velocidad + 0.01;  // Aumentar la velocidad del asteroide
        }
        if (asteroides[5].getPosition().x > 1000 || asteroides[5].getPosition().y < -150) // Si el asteroide sale de la pantalla por la derecha o por arriba...
        {
            aleatorio = std::rand() % 1001;                           // Generar un numero aleatorio entre 0 y 1000
            asteroides[5].setPosition(sf::Vector2f(-100, aleatorio)); // Posicion inicial del asteroide
            asteroides[5].velocidad = asteroides[5].velocidad + 0.01; // Aumentar la velocidad del asteroide
        }

        if (alien.getPosition().x > 1000) // Si el alien sale de la pantalla por la derecha...
        {
            aleatorio = std::rand() % 1001;                   // Generar un numero aleatorio entre 0 y 1000
            alien.setPosition(sf::Vector2f(-300, aleatorio)); // Posicion inicial del alien
            alien.velocidad = alien.velocidad + 0.05;         // Aumentar la velocidad del alien
        }

        // ----------------------------------------------------- Nave moviendose a traves del teclado

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) // Si se presiona la tecla izquierda
        {
            nave.move(nave.velocidad * -1, 0); // Mover la nave a la izquierda
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            nave.move(nave.velocidad, 0);       // Mover la nave a la derecha
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            nave.move(0, nave.velocidad * -1);  // Mover la nave hacia arriba
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            nave.move(0, nave.velocidad);       // Mover la nave hacia abajo
        }

        // --------------------------------------------- Disparar
        for (int i2 = 0; i2 < 20; i2++) // Para cada una de las balas...
        {
            if (balas[i2].disparo == true) // Si la bala se ha disparado...
            {
                balas[i2].velocidad = 0.5;                                                // Velocidad de la bala
                balas[i2].move(balas[i2].velocidad * a[i2], balas[i2].velocidad * b[i2]); // Mover la bala en la direccion que se disparo
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::V) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::X) || sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            if (teclaEspacio == false) // Si se presiona la tecla espacio...
            {
                balas[i].setPosition(nave.getPosition() + sf::Vector2f(50, 50)); // Posicion inicial de la bala
                balas[i].disparo = true;                                         // Dar la orden de disparar

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) // Bala hacia la derecha
                {
                    a[i] = 1; // Direccion en x de la bala
                    b[i] = 0; // Direccion en y de la bala
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) // Bala hacia la izquierda
                {
                    a[i] = -1; // Direccion en x de la bala
                    b[i] = 0;  // Direccion en y de la bala
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) // Bala hacia arriba
                {
                    a[i] = 0;  // Direccion en x de la bala
                    b[i] = -1; // Direccion en y de la bala
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) // Bala hacia abajo
                {
                    a[i] = 0; // Direccion en x de la bala
                    b[i] = 1; // Direccion en y de la bala
                }

                teclaEspacio = true; // Indicar que la bala ya se disparó
                i++;                 // Aumentar el indice de la matriz de balas
                if (i == 19)         // Si se llega al final de la matriz de balas...
                {
                    i = 0; // Reiniciar el indice de la matriz de balas
                }
                balas[i].disparo = false; // Indicar que la bala no se ha disparado
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) // Si se presiona la tecla espacio...
        {
            teclaEspacio = false; // Indicar que la bala no se ha disparado
        }

        // Actualizar animacion

        nave.update();
        for (int i2 = 0; i2 < 20; i2++)
        {
            balas[i2].update();
        }
        for (int i2 = 0; i2 < 6; i2++)
        {
            asteroides[i2].update();
        }
        alien.update();
        vida1.update();
        vida2.update();
        vida3.update();

        window.clear();

        nave.draw(window);
        for (int i2 = 0; i2 < 20; i2++)
        {
            balas[i2].draw(window);
        }
        for (int i2 = 0; i2 < 6; i2++)
        {
            asteroides[i2].draw(window);
        }
        alien.draw(window);
        window.draw(score);
        vida1.draw(window);
        vida2.draw(window);
        vida3.draw(window);

        window.display();
    }

    return 0;
}