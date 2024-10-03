#pragma once
#include <SFML/Graphics.hpp>

class GameStrategy
{
  public:
    virtual ~GameStrategy() = default;
    virtual void runStrategy(sf::RenderWindow &window) = 0;
};
