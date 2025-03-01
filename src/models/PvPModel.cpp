#include "PvPModel.h"

PvPGame::PvPModel::PvPModel()
{
    _ball.setRadius(20);
    _ball.setPosition(400, 300);
    _ball.setFillColor(sf::Color::White);
    _ballVelocity = sf::Vector2f(-5.f, 3.f);

    _leftPaddle.setSize(sf::Vector2f(10, 100));
    _leftPaddle.setPosition(50, 250);
    _leftPaddle.setFillColor(sf::Color::White);

    _rightPaddle.setSize(sf::Vector2f(10, 100));
    _rightPaddle.setPosition(740, 250);
    _rightPaddle.setFillColor(sf::Color::White);
}

void PvPGame::PvPModel::updateBall()
{
    _ball.move(_ballVelocity);

    if (_ball.getPosition().y <= 0 || _ball.getPosition().y >= 590)
    {
        _ballVelocity.y = -_ballVelocity.y;
    }
}

void PvPGame::PvPModel::checkCollision()
{
    if (_ball.getGlobalBounds().intersects(_leftPaddle.getGlobalBounds()) ||
        _ball.getGlobalBounds().intersects(_rightPaddle.getGlobalBounds()))
    {
        _ballVelocity.x = -_ballVelocity.x;
    }
}

int PvPGame::PvPModel::getLeftScore() const
{
    return _leftScore;
}

int PvPGame::PvPModel::getRightScore() const
{
    return _rightScore;
}
