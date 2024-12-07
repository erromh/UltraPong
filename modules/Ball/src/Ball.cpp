#include "Ball.h"

Ball::Ball()
{
    _ballShape.setPosition(BALLXCOORDINATE, BALLYCOORDINATE);
    _ballShape.setRadius(BALLRADIUS);
    _ballShape.setFillColor(sf::Color::White);

    _speedX = rand() % 10;
    _speedY = rand() % 10;

    _ballVelocity = sf::Vector2f(_speedX, _speedY);
}

sf::CircleShape Ball::getShape() const
{
    return _ballShape;
}

sf::Vector2f Ball::getPosition() const
{
    return _ballShape.getPosition();
}

void Ball::update(float &deltatime)
{
    _ballShape.move(_ballVelocity * _speedX); // * deltatime);
}

float Ball::getSpeedX()
{
    return _speedX;
}

void Ball::setSpeedX()
{
    _speedX *= -1;
}

void Ball::ballMoving()
{
    //_ballShape.move(_ballVelocity * );
}
