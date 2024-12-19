#pragma once
#include <SFML/Graphics.hpp>
#include <ctime>
#include <iostream>
#include <random>

#include "GlobalVaribles.h"

class Ball
{
  private:
    sf::CircleShape _ballShape;
    sf::Vector2f _ballVelocity;

    const float _initialSpeed = 200.f;

    float _speedX;
    float _speedY;

    std::random_device _rd;
    std::mt19937 _gen;

  public:
    Ball(float radius, float startX, float startY, float speedX, float speedY);

    Ball();

    void ballMoving();
    void update(float &deltatime);

    sf::Vector2f getPosition() const;
    sf::CircleShape getShape() const;

    float getSpeedX();
    void changeXDirection();

    float getSpeedY();
    void changeYDirection();
};
