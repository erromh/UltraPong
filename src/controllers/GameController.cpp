#include "GameController.h"

Controllers::GameController::GameController()
{
}

Controllers::GameController *Controllers::GameController::getInstance()
{
    static GameController instance;
    return &instance;
}

void Controllers::GameController::handleInput(sf::RenderWindow &window)
{
    if (_currentState)
    {
        _currentState->handleInput(window);
    }
}

void Controllers::GameController::setState(std::unique_ptr<GameState> newState)
{
    std::cout << "State changed on: " << typeid(*newState).name() << std::endl;

    _nextState = std::move(newState);
    _stateChanged = true;
}

void Controllers::GameController::update(float deltaTime)
{
    if (_currentState)
    {
        _currentState->update(deltaTime);
    }
}

void Controllers::GameController::render(sf::RenderWindow &window)
{
    if (_currentState)
    {
        _currentState->render(window);
    }
}

void Controllers::GameController::handleEvent(sf::Event &event)
{
    if (_currentState)
    {
        _currentState->handleEvent(event);
    }
}

void Controllers::GameController::runGame(sf::RenderWindow &window)
{
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

            handleEvent(event);
        }

        float deltaTime = clock.restart().asSeconds();

        handleInput(window);
        update(deltaTime);
        window.clear(sf::Color::Black);
        render(window);
        window.display();

        if (_stateChanged)
        {
            _currentState = std::move(_nextState);
            _stateChanged = false;
        }
    }
}
