#pragma once
#include <iostream>

#include "GameController.h"
#include "PvPModel.h"
#include "PvPView.h"

class State;

namespace PvPGame
{
class PvPController
{
  private:
    PvPModel &_pvpModel;
    PvPView &_pvpView;

  public:
    PvPController(PvPModel &model, PvPView &view);
    void handleInput(sf::RenderWindow &window);
    void update(float &deltaTime);
    void draw(sf::RenderWindow &window);
    void handleEvent(sf::Event &event);
};
} // namespace PvPGame
