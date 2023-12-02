#include <SFML/Graphics.hpp>

class Personaje
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    double velocidad = 0.1; // Moverlo a propiedades del personaje
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
};

class Enemigo // asteroides y alien son enemigos
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    double velocidad = 0.1; // Moverlo a propiedades del personaje
public:
    Enemigo(sf::Vector2f position, std::string name)
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

    void travel(int distancia)
    {
        distancia++;
        if (distancia == 15000)
        {
            velocidad = velocidad * -1;
            distancia = 0;
        }
    }
};

int main()
{
    int da1 = 0;
    int da2 = 0;
    int da3 = 0;
    int da4 = 0;
    int da5 = 0;

    sf::RenderWindow window(sf::VideoMode(1000, 800), "Asteroids");

    Personaje nave(sf::Vector2f(350, 250), "Nave");         // Posicion inicial de la nave
    Enemigo a1(sf::Vector2f(450, -200), "AsteroideGrande"); // Posicion inicial del asteroide 1 (hacia abajo)
    Enemigo a2(sf::Vector2f(150, 800), "AsteroideChico");   // Posicion inicial del asteroide 2 (hacia arriba)
    Enemigo a3(sf::Vector2f(-150, 50), "AsteroideChico");   // Posicion inicial del asteroide 3 (hacia derecha)
    Enemigo a4(sf::Vector2f(800, 500), "AsteroideGrande");  // Posicion inicial del asteroide 4 (hacia izquierda)
    Enemigo a5(sf::Vector2f(-300, 300), "Alien");           // Posicion inicial del alien 1 (hacia derecha)

    // Lo que podemos hacer para que vayan aumentando el numero de asteroides es que entre mas asteroides destruye, mas se reduce
    // la distancia de inicio y la amplitud de regreso.

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        a1.move(0, a1.velocidad);
        da1++;
        if (da1 == 15000) // <------------------ Este es el valor que iremos reduciendo para que los asteroides aumenten
        {
            a1.velocidad = a1.velocidad * -1;
            da1 = 0;
        }
        // a1.travel(-200);

        a2.move(0, a2.velocidad * -1);
        da2++;
        if (da2 == 15000)
        {
            a2.velocidad = a2.velocidad * -1;
            da2 = 0;
        }
        // a2.travel(800);

        a3.move(a3.velocidad, 0);
        da3++;
        if (da3 == 15000)
        {
            a3.velocidad = a3.velocidad * -1;
            da3 = 0;
        }

        a4.move(a4.velocidad * -1, 0);
        da4++;
        if (da4 == 15000)
        {
            a4.velocidad = a4.velocidad * -1;
            da4 = 0;
        }

        a5.move(a5.velocidad, 0);
        da5++;
        if (da5 == 15000)
        {
            a5.velocidad = a5.velocidad * -1;
            da5 = 0;
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            nave.move(nave.velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            nave.move(nave.velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            nave.move(0, nave.velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            nave.move(0, nave.velocidad);
        }

        // Actualizar animacion
        nave.update();
        a1.update();
        a2.update();
        a3.update();
        a4.update();
        a5.update();

        window.clear();

        nave.draw(window);
        a1.draw(window);
        a2.draw(window);
        a3.draw(window);
        a4.draw(window);
        a5.draw(window);

        window.display();
    }

    return 0;
}