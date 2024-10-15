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

        handlePlayerMovement(sf::Keyboard::S, sf::Keyboard::W, _leftPlayer);
        handlePlayerMovement(sf::Keyboard::Down, sf::Keyboard::Up, _rightPlayer);

        _leftPlayer->update(deltatime);
        _rightPlayer->update(deltatime);

        window.clear(sf::Color::Blue);

        window.draw(_leftPlayer->getPlayerShape());
        window.draw(_rightPlayer->getPlayerShape());

        window.display();
    }
}

void PvPMode::handlePlayerMovement(const sf::Keyboard::Key downKey, const sf::Keyboard::Key upKey, Players *player)
{
    if (sf::Keyboard::isKeyPressed(downKey))
    {
        _moveDownCommand->execute(player);
    }
    else if (sf::Keyboard::isKeyPressed(upKey))
    {
        _moveUpCommand->execute(player);
    }
    else
    {
        player->stopMoving();
    }
}

PvPMode::~PvPMode()
{
    delete _leftPlayer;
    delete _rightPlayer;
}
