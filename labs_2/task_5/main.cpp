#include "circle.hpp"
#include "game.hpp"

int main()
{
    sd::Game game(1000, 800, "Game");
    game.Setup(10);

    game.LifeCycle();

    return 0;
}