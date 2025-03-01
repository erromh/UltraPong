#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameController.h"
#include "GameState.h"
#include "PvPController.h"
#include "PvPModel.h"
#include "PvPView.h"

namespace PvPGame
{
class PvPState : public GameState
{
  private:
    PvPController _controller;
    PvPView _view;
    PvPModel _model;

  public:
    PvPState();
    void handleInput(sf::RenderWindow &window) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow &window) override;
    void handleEvent(sf::Event &event) override;
};
} // namespace PvPGame
