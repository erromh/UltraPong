#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class Players
{
  private:
    float _x;
    float _y;

    float _speed = 150;

    sf::Vector2f _velocity;

    sf::Clock _clock;
    sf::Time dt;

    sf::RectangleShape _playersShape;

  public:
    Players(float x, float y);
    Players();

    sf::RectangleShape getPlayerShape();

    void moveUp();
    void moveDown();

    void update(float deltatime);
    void stopMoving();
};
