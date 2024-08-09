#include "include/Game.h"

Game::Game()
{
    _gameWindow =
        std::make_unique<sf::RenderWindow>(sf::VideoMode(WINWIDTH, WINHEIGHT), "Ultra Pong", sf::Style::Default);

    _gameBall = std::make_unique<Ball>(BALLRADIUS, BALLXCOORDINATE, BALLYCOORDINATE);
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

        _gameWindow.get()->clear(sf::Color::Blue);
        _gameWindow.get()->draw(_gameBall.get()->getShape());
        _gameWindow.get()->display();
    }
}
