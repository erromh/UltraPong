#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

#include "MenuModel.h"
#include "MenuView.h"

namespace Menu
{
class MenuController
{
  private:
    MenuModel _model;
    MenuView _view;

  public:
    MenuController(sf::RenderWindow &window);
    void handleInput(sf::RenderWindow &window);
    void updateView();
    void draw(sf::RenderWindow &window);
    void handleEvent(sf::Event &event);
    // std::string getSelectedOption() const;
};
} // namespace Menu
