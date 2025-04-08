#pragma once
#include <SFML/Graphics.hpp>

#include "ExitController.h"
#include "ExitModel.h"
#include "ExitView.h"
#include "GameState.h"

namespace Exit
{
class State : public GameState
{
  private:
    Model _model;
    View _view;
    Controller _controller;
    sf::RenderWindow &_window;

  public:
    State(sf::RenderWindow &window);
    void handleInput(sf::RenderWindow &window) override;
    void handleEvent(sf::Event &event) override;
    void render(sf::RenderWindow &window) override;
    void update(float deltaTime) override;
};
} // namespace Exit
