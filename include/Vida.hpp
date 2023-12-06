#include <Imagen.hpp>

class Vida : public Imagen
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    Vida(sf::Vector2f position, std::string name) : Imagen(position, name)
    {
        if (!texture.loadFromFile("assets/images/" + name + ".png")) // Cargar imagen
        {
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
    }

    void move(float offsetX, float offsetY) // Mover enemigo (asteroide o alien) en x o y
    {
        sprite.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow &window) // Dibujar enemigo (asteroide o alien)
    {
        window.draw(this->sprite);
    }

    void update() // Actualizar animación
    {
    }

    void setPosition(sf::Vector2f newPosition) // Cambiar posición del enemigo (asteroide o alien)
    {
        sprite.setPosition(newPosition);
    }

    sf::Vector2f getPosition() // Obtener posición del enemigo (asteroide o alien)
    {
        return sprite.getPosition();
    }
};