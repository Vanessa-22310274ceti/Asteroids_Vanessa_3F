class Bala
{
private:
    sf::Texture texture;
    sf::Sprite sprite;

public:
    double velocidad = 0.1;
    sf::Vector2f position;
    bool disparo = false;

public:
    Bala(sf::Vector2f position, std::string name)
    {
        if (!texture.loadFromFile("assets/images/" + name + ".png")) // Cargar imagen
        {
        }
        this->sprite = sf::Sprite(texture);
        this->sprite.setPosition(position); // Posición inicial sprite
    }

    void move(float offsetX, float offsetY) // Mover bala en x o y
    {
        sprite.move(offsetX, offsetY);
    }

    void draw(sf::RenderWindow &window) // Dibujar bala
    {
        window.draw(this->sprite);
    }

    void update() // Actualizar animación
    {
    }

    void setPosition(sf::Vector2f newPosition) // Cambiar posición de la bala
    {
        sprite.setPosition(newPosition);
    }

    sf::Vector2f getPosition() // Obtener posición de la bala
    {
        return sprite.getPosition();
    }
};