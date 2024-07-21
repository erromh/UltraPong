#pragma once
#include <SFML/Graphics.hpp>

class Players
{
  private:
    float _x;
    float _y;

    sf::RectangleShape playersShape;

  public:
    Players(float &x, float &y);

    void moveUp();

    void moveDown();

    sf::RectangleShape getPlayerShape();
};
