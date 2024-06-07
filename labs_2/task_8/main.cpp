#include <SFML/Graphics.hpp>
#include <Circle.hpp>
#include <Game.hpp>

int main()
{
    mt::Game game(1980, 1040, "Game");

    if (!game.Setup(2))
        return -1;

    game.LifeCycle();

    return 0;
}