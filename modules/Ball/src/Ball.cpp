#include "Ball.h"

Ball::Ball()
{
    _ballShape.setPosition(BALLXCOORDINATE, BALLYCOORDINATE);
    _ballShape.setRadius(BALLRADIUS);
    _ballShape.setFillColor(sf::Color::White);
}

sf::CircleShape Ball::getShape() const
{
    return _ballShape;
}

sf::Vector2f Ball::getPosition() const
{
    return _ballShape.getPosition();
}
