#include <SFML/Graphics.hpp>
#include "figures.hpp"
#include <memory>

int main() {
    const int amount = 10;
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(1000, 800), "figures");
    std::vector<std::unique_ptr<sd::Shape>> types;


    for (unsigned int i = 0; i < amount; ++i) {
        int whatShape = rand() % 4;

        float x = static_cast<float>(rand() % 500);
        float y = static_cast<float>(rand() % 500);

        switch (whatShape) {
            case 0:
                types.push_back(std::make_unique<sd::Rectangle>(x, y, 100.f, 50.f));
            break;
            case 1:
                types.push_back(std::make_unique<sd::Line>(x, y, x - 100, y + 200));
            break;
            case 2:
                types.push_back(std::make_unique<sd::Circle>(x, y, 70.f));
            break;
            case 3:
                types.push_back(std::make_unique<sd::Triangle>(x, y, x + 150, y, x + 100, y + 50));
            break;
        }
    }

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();

        for (const auto& shape : types) {
            shape->draw(window);
        }

        window.display();
    }

    return 0;
}