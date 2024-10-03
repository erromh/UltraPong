#include "PvPMode.h"

PvPMode::PvPMode()
{
    _leftPlayer = new Players(30, 150);

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
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }

                if (event.key.code == sf::Keyboard::S)
                {
                    _moveDownCommand->execute(_leftPlayer);
                }

                if (event.key.code == sf::Keyboard::W)
                {
                    _moveUpCommand->execute(_leftPlayer);
                }
            }
        }

        window.clear(sf::Color::Blue);
        window.draw(_leftPlayer->getPlayerShape());
        window.display();
    }
}

PvPMode::~PvPMode()
{
    delete _leftPlayer;
}