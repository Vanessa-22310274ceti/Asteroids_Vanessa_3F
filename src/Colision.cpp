if (a1.getPosition() + sf::Vector2f(x, y) == nave.getPosition() + sf::Vector2f(50, 50)) // Si el area del asteroide 1 coincide con el area de la nave...
                {
                    vida1.setPosition(sf::Vector2f(-1000, -1000)); // Quitar una vida
                    nave.setPosition(sf::Vector2f(350, 250));      // Regresar la nave a su posicion inicial
                }
                if (a2.getPosition() + sf::Vector2f(x, y) == nave.getPosition() + sf::Vector2f(50, 50)) // Si el area del asteroide 2 coincide con el area de la nave...
                {
                    vida1.setPosition(sf::Vector2f(-1000, -1000)); // Quitar una vida
                    nave.setPosition(sf::Vector2f(350, 250));      // Regresar la nave a su posicion inicial
                }
                if (a3.getPosition() + sf::Vector2f(x, y) == nave.getPosition() + sf::Vector2f(50, 50)) // Si el area del asteroide 3 coincide con el area de la nave...
                {
                    vida1.setPosition(sf::Vector2f(-1000, -1000)); // Quitar una vida
                    nave.setPosition(sf::Vector2f(350, 250));      // Regresar la nave a su posicion inicial
                }
                if (a4.getPosition() + sf::Vector2f(x, y) == nave.getPosition() + sf::Vector2f(50, 50)) // Si el area del asteroide 4 coincide con el area de la nave...
                {
                    vida1.setPosition(sf::Vector2f(-1000, -1000)); // Quitar una vida
                    nave.setPosition(sf::Vector2f(350, 250));      // Regresar la nave a su posicion inicial
                }
                if (a5.getPosition() + sf::Vector2f(x, y) == nave.getPosition() + sf::Vector2f(50, 50)) // Si el area del alien 1 coincide con el area de la nave...
                {
                    vida1.setPosition(sf::Vector2f(-1000, -1000)); // Quitar una vida
                    nave.setPosition(sf::Vector2f(350, 250));      // Regresar la nave a su posicion inicial
                } 
                
// ------------------------------------------------ Colisiones
        for (int x = 0; x < 100; x++) // Analizar que el area del objeto no coincida con el del otro
        {
            for (int y = 0; y < 100; y++)
            {
                for (int x2 = 0; x2 <100; x2++)
                {
                    for (int y2 = 0; y2 < 100; y2++)
                    {
                        if (balas[i2].getPosition() + sf::Vector2f(x, y) == asteroides[0][0].getPosition() + sf::Vector2f(x2, y2)) // Si la bala choca con el asteroide 1...
                        {
                            asteroides[0][0].setPosition(sf::Vector2f(-4000, -3000)); // Mover el asteroide 1 fuera de la pantalla
                            balas[i2].setPosition(sf::Vector2f(-4000, -3000));       // Mover la bala fuera de la pantalla
                            balas[i2].disparo = false;                                // Indicar que la bala no se ha disparado
                            score.setString("score " + std::to_string(std::stoi(score.getString().toAnsiString()) + 1)); // Aumentar el score
                        }
                        if (balas[i2].getPosition() + sf::Vector2f(x, y) == asteroides[1][0].getPosition() + sf::Vector2f(x2, y2)) // Si la bala choca con el asteroide 2...
                        {
                            asteroides[1][0].setPosition(sf::Vector2f(-4000, -3000)); // Mover el asteroide 2 fuera de la pantalla
                            balas[i2].setPosition(sf::Vector2f(-4000, -3000));       // Mover la bala fuera de la pantalla
                            balas[i2].disparo = false;                                // Indicar que la bala no se ha disparado
                            score.setString("score " + std::to_string(std::stoi(score.getString().toAnsiString()) + 1)); // Aumentar el score
                        }
                        if (balas[i2].getPosition() + sf::Vector2f(x, y) == asteroides[2][0].getPosition() + sf::Vector2f(x2, y2)) // Si la bala choca con el asteroide 3...
                        {
                            asteroides[2][0].setPosition(sf::Vector2f(-4000, -3000)); // Mover el asteroide 3 fuera de la pantalla
                            balas[i2].setPosition(sf::Vector2f(-4000, -3000));       // Mover la bala fuera de la pantalla
                        }
                    }
                }
            }
        }

// ------------------------------------------------ Colisiones
        for (int x = 0; x < 10; x++) // Analizar que el area del objeto no coincida con el del otro
        {
            for (int y = 0; y < 10; y++)
            {
                for (int x2 = 10; x2 <90; x2+79)
                {
                    for (int y2 = 10; y2 < 90; y2+79)
                    {
                        if (balas[1].getPosition() + sf::Vector2f(x, y) == a1.getPosition() + sf::Vector2f(x2, y2)) // Si la bala choca con el asteroide 1...
                        {
                            a1.setPosition(sf::Vector2f(-1000, -1000)); // Mover el asteroide 1 fuera de la pantalla
                            //balas[i2].setPosition(sf::Vector2f(-4000, -3000));       // Mover la bala fuera de la pantalla
                            balas[1].disparo = false;                                // Indicar que la bala no se ha disparado
                            //score.setString("score " + std::to_string(std::stoi(score.getString().toAnsiString()) + 1)); // Aumentar el score
                        }
                        if (balas[1].getPosition() + sf::Vector2f(x, y) == a2.getPosition() + sf::Vector2f(x2, y2)) // Si la bala choca con el asteroide 2...
                        {
                            a2.setPosition(sf::Vector2f(-1000, -1000)); // Mover el asteroide 2 fuera de la pantalla
                            //balas[i2].setPosition(sf::Vector2f(-4000, -3000));       // Mover la bala fuera de la pantalla
                            balas[1].disparo = false;                                // Indicar que la bala no se ha disparado
                            //score.setString("score " + std::to_string(std::stoi(score.getString().toAnsiString()) + 1)); // Aumentar el score
                        }
                        if (balas[1].getPosition() + sf::Vector2f(x, y) == a2.getPosition() + sf::Vector2f(x2, y2)) // Si la bala choca con el asteroide 3...
                        {
                            a3.setPosition(sf::Vector2f(-1000, -1000)); // Mover el asteroide 3 fuera de la pantalla
                            //balas[i2].setPosition(sf::Vector2f(-4000, -3000));       // Mover la bala fuera de la pantalla
                            balas[1].disparo = false;                                // Indicar que la bala no se ha disparado
                            //score.setString("score " + std::to_string(std::stoi(score.getString().toAnsiString()) + 1)); // Aumentar el score
                        }
                    }
                }
            }
        }