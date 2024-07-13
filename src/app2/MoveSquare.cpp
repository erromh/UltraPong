#include "MoveSquare.h"

MoveSquare::MoveSquare(double &x, double &y) : _x(x), _y(y)
{
    movingSquare.setFillColor(sf::Color(0, 255, 0));
    movingSquare.setSize(sf::Vector2f(30, 30));
    movingSquare.setPosition(_x, _y);
}

void MoveSquare::moveItem()
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        _y -= .1;
        movingSquare.setPosition(_x, _y);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        _y += .1;
        movingSquare.setPosition(_x, _y);
    }
}

sf::RectangleShape MoveSquare::getItem()
{
    return movingSquare;
}
