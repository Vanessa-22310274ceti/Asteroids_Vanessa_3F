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

    sf::Vector2f getPosition()
    {
        return sprite.getPosition();
    }

    void setPosition(sf::Vector2f newPosition)
    {
        sprite.setPosition(newPosition);
    }
};