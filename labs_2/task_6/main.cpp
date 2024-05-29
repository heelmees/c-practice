#include <iostream>
#include "SFML/Graphics.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 630), "game");
    sf::Texture spaceTexture;
    sf::Texture ufoTexture;
    sf::Sprite spriteSpaceTexture;
    sf::Sprite spriteUFOTexture;

    if (!spaceTexture.loadFromFile("src\\plants.jpg"))
    {
        std::cout << "Error!!! plants.jpg is not loading!" << std::endl;
        return false;
    }
    if (!ufoTexture.loadFromFile("src\\monstrenok.png"))
    {
        std::cout << "Error!!! monstrenok.png is not loading!" << std::endl;
        return false;
    }

    spriteSpaceTexture.setTexture(spaceTexture);
    spriteUFOTexture.setTexture(ufoTexture);
    spriteUFOTexture.setPosition(600, 315);
    spriteUFOTexture.setScale(0.25f, 0.25f);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //управл.
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            spriteUFOTexture.move(0.0f, -0.5f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            spriteUFOTexture.move(0.0f, 0.5f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            spriteUFOTexture.move(-0.5f, 0.0f);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            spriteUFOTexture.move(0.5f, 0.0f);
        }

        window.clear();

        window.draw(spriteSpaceTexture);
        window.draw(spriteUFOTexture);

        window.display();
    }

    return 0;
}