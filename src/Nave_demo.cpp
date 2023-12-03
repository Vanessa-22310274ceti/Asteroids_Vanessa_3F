#include <SFML/Graphics.hpp>


class Imagen
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Imagen(sf::Vector2f position, std::string name)
    {

        // Cargar la imagen desde un archivo

        if (!texture.loadFromFile("assets/images/" + name + ".png"))
        {
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(this->sprite);
    }

    void update()
    {
    }
};



class Personaje
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    double velocidad = 0.1; // Moverlo a propiedades del personaje
    sf::Vector2f position;

public:
    Personaje(sf::Vector2f position, std::string name)
    {

        // Cargar la imagen desde un archivo

        if (!texture.loadFromFile("assets/images/" + name + ".png"))
        {
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
    }

    void move(float offsetX, float offsetY)
    {
        sprite.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow &window)
    {
        window.draw(this->sprite);
    }

    void update()
    {
    }

    sf::Vector2f getPosition()
    {
        return sprite.getPosition();
    }
};

class Enemigo // asteroides y alien son enemigos
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    double velocidad = 0.1; // Moverlo a propiedades del personaje
    sf::Vector2f position;
    bool disparo = false;
public:
    Enemigo(sf::Vector2f position, std::string name)
    {
        if (!texture.loadFromFile("assets/images/" + name + ".png")) // Cargar imagen
        {
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position);     // Posición inicial sprite
    }

    void move(float offsetX, float offsetY)     // Mover enemigo (asteroide o alien) en x o y
    {
        sprite.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow &window)         // Dibujar enemigo (asteroide o alien)
    {
        window.draw(this->sprite);
    }

    void update()                               // Actualizar animación
    {
    }

    void setPosition(sf::Vector2f newPosition)  // Cambiar posición del enemigo (asteroide o alien)
    {
        sprite.setPosition(newPosition);
    }
};

int main()
{
    
    
    
    
    
    int da1 = 0;
    int da2 = 0;
    int da3 = 0;
    int da4 = 0;
    int da5 = 0;

    int i = 0;                      // Indice de la matriz balas
    int i2 = 0;                     // Indice del for de balas
    bool teclaEspacio = false;      // Para que no se dispare la bala varias veces mientras se mantiene presionada la tecla
    int a[20] = {0};                // Direccion en x de la bala
    int b[20] = {0};                // Direccion en y de la bala
    bool portadaOut = false;               // Para que no se repita la portada

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


    Imagen vida1 = Imagen(sf::Vector2f(0, 0), "Vida");         // Imagen de la vida 1
    Imagen vida2 = Imagen(sf::Vector2f(50, 0), "Vida");        // Imagen de la vida 2
    Imagen vida3 = Imagen(sf::Vector2f(100, 0), "Vida");       // Imagen de la vida 3

    Enemigo asteroides[5][1] = {
        {Enemigo(sf::Vector2f(450, -200), "AsteroideGrande")},
        {Enemigo(sf::Vector2f(150, 800), "AsteroideChico")},
        {Enemigo(sf::Vector2f(-150, 50), "AsteroideChico")},
        {Enemigo(sf::Vector2f(800, 500), "AsteroideGrande")},
        {Enemigo(sf::Vector2f(-300, 300), "Alien")}};

    Enemigo balas[20] = {                                   // Matriz de balas (solo se pueden usar 20 balas a la vez)
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")},
        {Enemigo(sf::Vector2f(-4000, -3000), "Bala")}};

    Personaje nave(sf::Vector2f(350, 250), "Nave");         // Posicion inicial de la nave
    nave.velocidad = 0.2;                                   // Velocidad de la nave

    Enemigo a1(sf::Vector2f(450, -200), "AsteroideGrande"); // Posicion inicial del asteroide 1 (hacia abajo)
    Enemigo a2(sf::Vector2f(150, 800), "AsteroideChico");   // Posicion inicial del asteroide 2 (hacia arriba)
    Enemigo a3(sf::Vector2f(-150, 50), "AsteroideChico");   // Posicion inicial del asteroide 3 (hacia derecha)
    Enemigo a4(sf::Vector2f(800, 500), "AsteroideGrande");  // Posicion inicial del asteroide 4 (hacia izquierda)
    Enemigo a5(sf::Vector2f(-300, 300), "Alien");           // Posicion inicial del alien 1 (hacia derecha)

    // Lo que podemos hacer para que vayan aumentando el numero de asteroides es que entre mas asteroides destruye, mas se reduce
    // la distancia de inicio y la amplitud de regreso.

    while (window.isOpen())                         // Mientras la ventana esté abierta
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
        a1.move(0, a1.velocidad);                // Mover el asteroide 1
        da1++;                                   // Contador para que el asteroide cambie de direccion
        if (da1 == 15000)                        // Si el asteroide sale de la pantalla, cambia de direccion
        {
            a1.velocidad = a1.velocidad * -1;    // El asteroide se regresa por donde vino
            da1 = 0;                             // Reinicia el contador
        }

        a2.move(0, a2.velocidad * -1);          // Mover el asteroide 2
        da2++;                                  // Contador para que el asteroide cambie de direccion
        if (da2 == 15000)                       // Si el asteroide sale de la pantalla, cambia de direccion
        {
            a2.velocidad = a2.velocidad * -1;   // El asteroide se regresa por donde vino
            da2 = 0;                            // Reinicia el contador
        }

        a3.move(a3.velocidad, 0);               // Mover el asteroide 3
        da3++;                                  // Contador para que el asteroide cambie de direccion
        if (da3 == 15000)                       // Si el asteroide sale de la pantalla, cambia de direccion
        {
            a3.velocidad = a3.velocidad * -1;   // El asteroide se regresa por donde vino
            da3 = 0;                            // Reinicia el contador
        }

        a4.move(a4.velocidad * -1, 0);          // Mover el asteroide 4
        da4++;                                  // Contador para que el asteroide cambie de direccion
        if (da4 == 15000)                       // Si el asteroide sale de la pantalla, cambia de direccion
        {
            a4.velocidad = a4.velocidad * -1;   // El asteroide se regresa por donde vino
            da4 = 0;                            // Reinicia el contador
        }

        a5.move(a5.velocidad, 0);               // Mover el alien 1
        da5++;                                  // Contador para que el alien cambie de direccion
        if (da5 == 15000)                       // Si el alien sale de la pantalla, cambia de direccion
        {
            a5.velocidad = a5.velocidad * -1;   // El alien se regresa por donde vino
            da5 = 0;                            // Reinicia el contador
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))     // Si se presiona la tecla izquierda
        {
            nave.move(nave.velocidad * -1, 0);                  // Mover la nave a la izquierda
/*
            for (int i2 = 0; i2 < 20; i2++)                     // Para cada una de las balas...
            {
                if (balas[i2].disparo == false)                 // Si la bala no se ha disparado...
                {
                    balas[i2].move(balas[i2].velocidad * -1, 0); // Mover la bala a la izquierda junto con la nave
                }
            }*/
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            nave.move(nave.velocidad, 0);
            /*
            for (int i2 = 0; i2 < 20; i2++)
            {
                if (balas[i2].disparo == false)
                {
                    balas[i2].move(balas[i2].velocidad, 0);
                }
            }*/
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            nave.move(0, nave.velocidad * -1);
            /*
            for (int i2 = 0; i2 < 20; i2++)
            {
                if (balas[i2].disparo == false)
                {
                    balas[i2].move(0, balas[i2].velocidad * -1);
                }
            }*/
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            nave.move(0, nave.velocidad);
            /*
            for (int i2 = 0; i2 < 20; i2++)
            {
                if (balas[i2].disparo == false)
                {
                    balas[i2].move(0, balas[i2].velocidad);
                }
            }
            */
        }

        for (int i2 = 0; i2 < 20; i2++)                                                     // Para cada una de las balas...
        {
            if (balas[i2].disparo == true)                                                  // Si la bala se ha disparado... 
            {
                balas[i2].velocidad = 0.5;                                                  // Velocidad de la bala
                balas[i2].move(balas[i2].velocidad * a[i2], balas[i2].velocidad * b[i2]);   // Mover la bala en la direccion que se disparo
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::V) || sf::Keyboard::isKeyPressed(sf::Keyboard::Z) || sf::Keyboard::isKeyPressed(sf::Keyboard::X) || sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            if (teclaEspacio == false)                                              // Si se presiona la tecla espacio...
            {
                balas[i].setPosition(nave.getPosition() + sf::Vector2f(50, 50));    // Posicion inicial de la bala
                balas[i].disparo = true;                                            // Dar la orden de disparar

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) // Bala hacia la derecha
                {
                    a[i] = 1;           // Direccion en x de la bala
                    b[i] = 0;           // Direccion en y de la bala
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) // Bala hacia la izquierda
                {
                    a[i] = -1;          // Direccion en x de la bala
                    b[i] = 0;           // Direccion en y de la bala
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) // Bala hacia arriba
                {
                    a[i] = 0;           // Direccion en x de la bala
                    b[i] = -1;          // Direccion en y de la bala
                }

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)) // Bala hacia abajo
                {
                    a[i] = 0;           // Direccion en x de la bala
                    b[i] = 1;           // Direccion en y de la bala
                }

                teclaEspacio = true;        // Indicar que la bala ya se disparó
                i++;                        // Aumentar el indice de la matriz de balas
                if (i == 19)                // Si se llega al final de la matriz de balas...
                {
                    i = 0;                  // Reiniciar el indice de la matriz de balas
                }
                balas[i].disparo = false;   // Indicar que la bala no se ha disparado
            }
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))    // Si se presiona la tecla espacio...
        {
            teclaEspacio = false;                               // Indicar que la bala no se ha disparado
        }

        // Actualizar animacion
        vida1.update();
        vida2.update();
        vida3.update();
        nave.update();
        a1.update();
        a2.update();
        a3.update();
        a4.update();
        a5.update();
        for (int i2 = 0; i2 < 20; i2++)
        {
            balas[i2].update();
        }

        window.clear();

        window.draw(score);
        vida1.draw(window);
        vida2.draw(window);
        vida3.draw(window);
        nave.draw(window);
        a1.draw(window);
        a2.draw(window);
        a3.draw(window);
        a4.draw(window);
        a5.draw(window);
        for (int i2 = 0; i2 < 20; i2++)
        {
            balas[i2].draw(window);
        }

        window.display();
    }

    return 0;
}