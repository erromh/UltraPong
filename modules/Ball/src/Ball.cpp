#include "Ball.h"

Ball::Ball():_gen(_rd())
{
    _ballShape.setPosition(BALLXCOORDINATE, BALLYCOORDINATE);
    _ballShape.setRadius(BALLRADIUS);
    _ballShape.setFillColor(sf::Color::White);

    std::uniform_real_distribution<> xDistrib(400, 600);
    std::uniform_real_distribution<> yDistrib(400, 600);

    _speedX = xDistrib(_gen); 
    _speedY = yDistrib(_gen);

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
    _ballShape.move(_ballVelocity * deltatime);
}
  
float Ball::getSpeedX()
{
    return _speedX;
}

void Ball::changeXDirection()
{
    _ballVelocity.x *= -1;
}

float Ball::getSpeedY()
{
    return _speedY;
}

void Ball::changeYDirection()
{
    _ballVelocity.y *= -1;
}
