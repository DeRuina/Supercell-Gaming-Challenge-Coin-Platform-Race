#include "Game.hpp"


int main()
{
    //init random
    std::srand(static_cast<unsigned>(std::time(0)));

    //init game object
    Game game;

    //game loop
    while (game.running())
    {
        game.update();
        game.render();
    }
    return 0;
}