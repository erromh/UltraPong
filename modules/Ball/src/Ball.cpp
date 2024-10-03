#include "Ball.h"

Ball::Ball(float startX, float startY)
{
    _ballShape.setPosition(startX, startY);
    _ballShape.setSize(sf::Vector2f(30, 30));
    _ballShape.setFillColor(sf::Color::White);
}

sf::RectangleShape Ball::getShape() const
{
    return _ballShape;
}

sf::Vector2f Ball::getPosition() const
{
    return _ballShape.getPosition();
}
