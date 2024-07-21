#include "include/Ball.h"

Ball::Ball(float radius, float startX, float startY) : _ballShape(radius)
{
    _ballShape.setPosition(startX, startY);
    _ballShape.setFillColor(sf::Color::Red);
}

sf::CircleShape Ball::getShape() const
{
    return _ballShape;
}

sf::Vector2f Ball::getPosition() const
{
    return _ballShape.getPosition();
}
