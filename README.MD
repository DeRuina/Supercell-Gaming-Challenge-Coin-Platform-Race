# SUPERCELL Game Challenge
Had 12 hours to make a game with a topic and bugged structure SUPERCELL provided us with. This is the game I was able to make, the subject was making a platformer game.

# Coin Platform Race

Coin Platform Race is a multiplayer game where two players compete to collect coins and reach a certain number of points. The game is written in C++ and uses the SFML (Simple and Fast Multimedia Library) framework for game development.

## Game Rules

- The game is controlled using the arrow keys for Player 1 and WASD keys for Player 2.
- The first player to reach 150 points wins.
- The game includes different types of coins that give different point values.
- Touching the platforms resets the player's position.

## Project Structure

- `main.cpp`: The entry point of the game, where the game loop and initialization occur.
- `Coins.cpp` and `Coins.hpp`: Contains the implementation and definition of the coin objects.
- `Game.cpp` and `Game.hpp`: Contains the implementation and definition of the game logic and mechanics.
- `Player.cpp` and `Player.hpp`: Contains the implementation and definition of the player objects.
- `belagio`: Contains a font file used in the game.

## How to Run
```bash
1. make
2. ./Coin_Race
```

