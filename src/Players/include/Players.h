#pragma once
#include "Command.h"
#include <SFML/Graphics.hpp>

class Players
{
  private:
    float _x;
    float _y;

    sf::RectangleShape playersShape;

  public:
    Players(float &x, float &y);

    void handleInput(Command *moveUp, Command *moveDown);

    sf::RectangleShape getPlayerShape();

    void moveUp();
};
