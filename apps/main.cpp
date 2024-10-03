#include <SFML/Graphics.hpp>


#include "GameController.h"
#include "GlobalVaribles.h"

// https://habr.com/ru/articles/710100/

int main()
{
    sf::RenderWindow mainWindow(sf::VideoMode(WINWIDTH, WINHEIGHT), "", sf::Style::Default);
    GameController gameController(mainWindow);
    gameController.startMenu();

    return 0;
}
