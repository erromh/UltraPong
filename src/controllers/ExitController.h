#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "ExitModel.h"
#include "ExitView.h"
#include "GameController.h"
#include "MenuState.h"
#include "PvPState.h"

namespace Exit
{
class Controller
{
  private:
    Model _model;
    View _view;

  public:
    Controller(sf::RenderWindow &window);

  public:
    void handleEvent(sf::Event &event, sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
    void updateView();
};
} // namespace Exit
