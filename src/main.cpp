#include "include/Game.h"

int main()
{
    Game *newGame = new Game();

    newGame->startGame();

    delete newGame;

    return 0;
}
