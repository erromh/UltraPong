#include "PvPMode.h"

PvPMode::PvPMode()
{
    _leftPlayer = new Players(LEFTPLAYERXCOORDINATE, LEFTPLAYERYCOORDINATE);
    _rightPlayer = new Players(RIGHTPLAYERXCOORDINATE, RIGHTPLAYERYCOORDINATE);

    _moveDownCommand = PlayerMoveDownCommand::getInstance();
    _moveUpCommand = PlayerMoveUpCommand::getInstanse();
}

PvPMode &PvPMode::getInstance()
{
    static PvPMode instance;
    return instance;
}

void PvPMode::runStrategy(sf::RenderWindow &window)
{
    std::cout << "Pvp mode is working\n";

    while (window.isOpen())
    {
        float deltatime = _clock.restart().asSeconds();

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            _moveDownCommand->execute(_leftPlayer);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            _moveUpCommand->execute(_leftPlayer);
        }
        else
        {
            _leftPlayer->stopMoving();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            _moveDownCommand->execute(_rightPlayer);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            _moveUpCommand->execute(_rightPlayer);
        }
        else
        {
            _rightPlayer->stopMoving();
        }

        _leftPlayer->update(deltatime);
        _rightPlayer->update(deltatime);

        window.clear(sf::Color::Blue);

        window.draw(_leftPlayer->getPlayerShape());
        window.draw(_rightPlayer->getPlayerShape());

        window.display();
    }
}

PvPMode::~PvPMode()
{
    delete _leftPlayer;
    delete _rightPlayer;
}
