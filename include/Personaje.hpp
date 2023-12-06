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

    void setPosition(sf::Vector2f newPosition)
    {
        sprite.setPosition(newPosition);
    }
};