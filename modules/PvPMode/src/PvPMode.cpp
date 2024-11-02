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
    bool isLeftPlayerColliding = false;

    std::cout << "Pvp mode is working\n";

    window.setFramerateLimit(60);

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }
        }

        float deltatime = _clock.restart().asSeconds();

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

        CollisionHandler::getInstance().lowerPlayerCollision(player);
    }
    else if (sf::Keyboard::isKeyPressed(upKey))
    {
        _moveUpCommand->execute(player);

        CollisionHandler::getInstance().upperPlayerCollision(player);
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
