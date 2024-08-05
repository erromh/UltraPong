#include "include/Game.h"

Game::Game()
{
    _gameWindow =
        std::make_unique<sf::RenderWindow>(sf::VideoMode(WINWEIGHT, WINHEIGHT), "Ultra Pong", sf::Style::Default);
}

void Game::startGame()
{
    while (_gameWindow.get()->isOpen())
    {
        sf::Event event;

        while (_gameWindow.get()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                _gameWindow.get()->close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                _gameWindow.get()->close();
            }
        }

        _gameWindow.get()->clear(sf::Color::Green);
        _gameWindow.get()->display();
    }
}
