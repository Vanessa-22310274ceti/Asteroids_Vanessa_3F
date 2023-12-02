#include <SFML/Graphics.hpp>

class Personaje
{
private:
    sf::Texture texture;
    sf::Sprite sprite;
public:
    Personaje(sf::Vector2f position)
    {

        // Cargar la imagen desde un archivo
        
        if (!texture.loadFromFile("assets/images/Nave.png"))
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

    void update(){
        
    }
};

double velocidad = 0.1;

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Asteroids");

    Personaje nave(sf::Vector2f(350, 250));         // Nave

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            nave.move(velocidad * -1, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            nave.move(velocidad, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            nave.move(0, velocidad * -1);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            nave.move(0, velocidad);
        }

        // Actualizar animacion pikachu
        nave.update();

        window.clear();
        nave.draw(window);
        window.display();
    }

    return 0;
}