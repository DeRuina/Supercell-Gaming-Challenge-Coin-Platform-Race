#include "Game.hpp"


int main()
{
    //init random
    std::srand(static_cast<unsigned>(std::time(0)));

    //init game object
    Game game;
    Player Player1(0.f, 0.f, 0);
    Player Player2(0.f, 0.f, 1);
    game.setPlayer1(Player1);
    game.setPlayer2(Player2);
   

    //game loop
    while (game.running())
    {
        game.update();
        game.render();
    }
    return 0;
}