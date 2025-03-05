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

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                window.close();
            }

            Controllers::GameController::getInstance()->handleEvent(event);
        }

        float deltaTime = clock.restart().asSeconds();

        Controllers::GameController::getInstance()->handleInput(window);
        Controllers::GameController::getInstance()->update(deltaTime);

        window.clear(sf::Color::Black);

        Controllers::GameController::getInstance()->render(window);

        window.display();
    }
}
