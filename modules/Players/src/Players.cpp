#include "Players.h"

#include "GlobalVaribles.h"

Players::Players(float x, float y) : _x(x), _y(y)
{
    _playersShape.setPosition(_x, _y);
    _playersShape.setFillColor(sf::Color::White);
    _playersShape.setSize(sf::Vector2f(30, 150));
}

Players::Players()
{
}

sf::RectangleShape Players::getPlayerShape()
{
    return _playersShape;
}

void Players::moveUp()
{
    _playersShape.move(0, -100.0f);
}

void Players::moveDown()
{
    _playersShape.move(0, 100.0f);
}
