#include "GameController.h"

void Controllers::GameController::handleInput(sf::RenderWindow &window)
{
    if (_currentState)
    {
        _currentState->handleInput(window);
    }
}

void Controllers::GameController::setState(std::unique_ptr<GameState> newState)
{
    _currentState = std::move(newState);
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
    while (window.isOpen())
    {
        handleInput(window);
        update(1.0f / 60.0f);
        render(window);
    }
}
