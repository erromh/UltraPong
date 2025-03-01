#pragma once
#include <SFML/Graphics.hpp>

class GameState
{
  public:
    virtual void handleInput(sf::RenderWindow &window) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    virtual void handleEvent(sf::Event &event) = 0;
};
