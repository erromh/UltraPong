#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameController.h"
#include "GameState.h"
#include "MenuController.h"

namespace Menu
{
class MenuState : public GameState
{
  private:
    MenuController _menuController;

  public:
    void handleInput(sf::RenderWindow &window) override;
    void update(float deltaTime) override;
    void render(sf::RenderWindow &window) override;
    void handleEvent(sf::Event &event) override;
};
} // namespace Menu
