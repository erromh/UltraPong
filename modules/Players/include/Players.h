#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Players
{
  private:
    float _x;
    float _y;

    sf::RectangleShape _playersShape;

  public:
    Players(float x, float y);
    Players();

    sf::RectangleShape getPlayerShape();

    void moveUp();

    void moveDown();
};
