#include "Players.h"

#include "GlobalVaribles.h"

Players::Players(float x, float y) : _x(x), _y(y)
{
    _playersShape.setPosition(_x, _y);
    _playersShape.setFillColor(sf::Color::White);
    _playersShape.setSize(sf::Vector2f(30, 150));

    dt = _clock.restart();

    _velocity = sf::Vector2f(0, 0);
}

Players::Players()
{
}

sf::RectangleShape Players::getPlayerShape()
{
    return _playersShape;
}

void Players::stopMoving()
{
    _velocity.y = 0;
}

void Players::update(float deltatime)
{
    _playersShape.move(_velocity * deltatime);
}

void Players::moveUp()
{
    _velocity.y = -_speed;
}

void Players::moveDown()
{
    _velocity.y = _speed;
}
