#include "GameController.h"

GameController::GameController(sf::RenderWindow &window) : _mainWindow(window)
{
#if defined(__linux__)
    _mainWindow.setTitle("Ultra Pong on Linux");
#elif _WIN32
    _mainWindow.setTitle("Ultra Pong on Windows");
#else
    _mainWindow.setTitle("Ultra Pong on other");
#endif

    if (!_icon.loadFromFile(_iconPath))
    {
        throw std::runtime_error("Failed to load icon\n");
    }

    _mainWindow.setIcon(_icon.getSize().x, _icon.getSize().y, _icon.getPixelsPtr());

    _gameFactory = std::make_unique<GameFactory>(_mainWindow);

    _menu = std::make_unique<GameMenu>(_mainWindow);
}

void GameController::startMenu()
{
    _mainWindow.setFramerateLimit(60);
    _mainWindow.setVerticalSyncEnabled(true);

    bool needsRedraw = true;

    while (_mainWindow.isOpen())
    {
        handleEvents(needsRedraw);

        // _mainWindow.clear(sf::Color::Black);

        /*if (sf::Keyboard::isKeyPressed(sf::Keyboard::C))
        {
            changeTheme();
        }

        if (!currentTheme)
        {
            _mainWindow.clear(sf::Color::Green);
        }*/

        if (needsRedraw)
        {
            _mainWindow.clear(sf::Color::Black);
            _menu->drawItems();
            _mainWindow.display();
            needsRedraw = false;
        }
    }
}

void GameController::changeTheme()
{
    // bool currentTheme = 1;

    if (currentTheme)
    {
        _mainWindow.clear(sf::Color::Yellow);
    }
}

void GameController::handleEvents(bool &needsRedraw)
{
    sf::Event event;

    while (_mainWindow.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            _mainWindow.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            _mainWindow.close();
        }

        if (event.type == sf::Event::KeyReleased)
        {
            switch (event.key.code)
            {
            case sf::Keyboard::W:
            case sf::Keyboard::Up:
                _menu->moveUp();
                needsRedraw = true;
                break;

            case sf::Keyboard::S:
            case sf::Keyboard::Down:
                _menu->moveDown();
                needsRedraw = true;
                break;

            case sf::Keyboard::Enter:
                switch (_menu->getSelectedMenuItem())
                {
                case 0:
                    std::cout << "Case 0 is working ...\n";
                    _gameFactory->createGameMode(_gameMap[0]);
                    break;

                case 1:
                    std::cout << "Case 1 is working ...\n";
                    break;

                case 2:
                    std::cout << "Case 2 is working ...\n";
                    break;

                case 3:
                    _mainWindow.close();
                    break;
                }

                break;
                needsRedraw = true;

            default:
                break;
            }
        }
    }
}
