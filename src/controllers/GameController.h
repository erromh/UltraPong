#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

#include "ExitModel.h"
#include "GameState.h"

namespace Controllers
{
class GameController
{
  private:
    std::unique_ptr<GameState> _currentState;
    std::unique_ptr<GameState> _nextState;
    bool _stateChanged = false;
    Exit::Model _exitModel;

  private:
    GameController();
    GameController(const GameController &) = delete;

  public:
    static GameController *getInstance();
    Exit::Model &getExitModel();
    void operator=(const GameController &) = delete;
    void setState(std::unique_ptr<GameState> newState);
    void handleInput(sf::RenderWindow &window);
    void update(float deltaTime);
    void render(sf::RenderWindow &window);
    void handleEvent(sf::Event &event);
    void runGame(sf::RenderWindow &window);
};
} // namespace Controllers
