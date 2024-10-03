#include "GameFactory.h"

GameFactory::GameFactory(sf::RenderWindow &window) : _factoryWindow(window)
{
}

void GameFactory::createGameMode(GameMode mode)
{
    switch (mode)
    {
    case GameMode::PvP:
        PvPMode::getInstance().runStrategy(_factoryWindow);
        break;

        /*case GameMode::Bot:
            return std::make_unique<BotMode>();

        case GameMode::Net:
            std::cout << "Network mode is comming ...\n";
            break;*/

    default:
        break;
    }
}
