#include "include/Players.h"

#include "GlobalVaribles.h"

Players::Players(float &x, float &y) : _x(x), _y(y)
{
    playersShape.setPosition(_x, _y);
    playersShape.setFillColor(sf::Color::White);
    playersShape.setSize(sf::Vector2f(30, 150));
}

sf::RectangleShape Players::getPlayerShape()
{
    return playersShape;
}

void Players::moveUp()
{
    playersShape.move(0, -200.0f);
}