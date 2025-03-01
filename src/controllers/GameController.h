#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "GameState.h"

namespace Controllers
{
class GameController
{
  private:
    std::unique_ptr<GameState> _currentState;
    GameController()
    {
    }

  public:
    static GameController *getInstance()
    {
        static GameController instance;
        return &instance;
    }

    GameController(const GameController &) = delete;
    void operator=(const GameController &) = delete;

    void setState(std::unique_ptr<GameState> newState);

    void handleInput(sf::RenderWindow &window);

    void update(float deltaTime);

    void render(sf::RenderWindow &window);

    void handleEvent(sf::Event &event);

    void runGame(sf::RenderWindow &window);
};
} // namespace Controllers
