#pragma once
#include <SFML/Graphics.hpp>

class Ball
{
  private:
    sf::RectangleShape _ballShape;
    sf::Vector2f _ballVelocity;

    const float _initialSpeed = 200.f;

    float _speedX;
    float _speedY;

  public:
    Ball(float radius, float startX, float startY, float speedX, float speedY);

    Ball(float startX, float startY);

    sf::Vector2f getPosition() const;
    sf::RectangleShape getShape() const;
};
