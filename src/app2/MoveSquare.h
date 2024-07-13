#pragma once
#include <SFML/Graphics.hpp>

class MoveSquare
{
  private:
    sf::RectangleShape movingSquare;

    float _x;
    float _y;

  public:
    MoveSquare(double &x, double &y);

    void moveItem();

    sf::RectangleShape getItem();
};
