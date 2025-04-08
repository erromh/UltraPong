#include "StartGame.h"

Start::StartGame *Start::StartGame::_instance = nullptr;

Start::StartGame *Start::StartGame::getInstatnce()
{
    return _instance;
}

Start::StartGame::StartGame()
{
}

Start::StartGame::~StartGame()
{
}

void Start::StartGame::startingGame()
{
    sf::RenderWindow window(sf::VideoMode(1700, 900), "UltraPong");

#if defined(__linux__)
    window.setTitle("Ultra Pong on Linux");
#elif _WIN32
    window.setTitle("Ultra Pong on Windows");
#else
    window.setTitle("Ultra Pong on other");
#endif

    window.setFramerateLimit(60);

    Controllers::GameController::getInstance()->setState(std::make_unique<Menu::MenuState>(window));

    Controllers::GameController::getInstance()->runGame(window);
}
