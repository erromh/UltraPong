#include "PvPModel.h"

PvPGame::PvPModel::PvPModel(sf::RenderWindow &window)
{
    _windowSize = window.getSize();
    float ballRadius = (_windowSize.y * 0.018f);

    _leftVelocity = sf::Vector2f(0.f, 0.f);
    _rightVelocity = sf::Vector2f(0.f, 0.f);
    _paddleSpeed = window.getSize().y * 0.7f;

    _ball.setRadius(ballRadius);
    _ball.setPosition(_windowSize.x / 2.0 - ballRadius, _windowSize.y / 2.0 - ballRadius);
    _ball.setFillColor(sf::Color::White);
    _ballVelocity = sf::Vector2f(-8.f, 5.f);

    float paddleWidth = _windowSize.x * 0.016f;
    float paddleHeight = _windowSize.y * 0.16f;

    _leftPaddle.setSize(sf::Vector2f(paddleWidth, paddleHeight));
    _leftPaddle.setPosition(_windowSize.x * 0.05f, _windowSize.y / 2.0 - paddleHeight / 2.0);
    _leftPaddle.setFillColor(sf::Color::White);

    _rightPaddle.setSize(sf::Vector2f(paddleWidth, paddleHeight));
    _rightPaddle.setPosition(_windowSize.x * 0.95f - paddleWidth, _windowSize.y / 2.0 - paddleHeight / 2.0);
    _rightPaddle.setFillColor(sf::Color::White);
}

void PvPGame::PvPModel::updateBall()
{
    _ball.move(_ballVelocity);
}

void PvPGame::PvPModel::checkBallCollision()
{
    if (_ball.getGlobalBounds().intersects(_leftPaddle.getGlobalBounds()) ||
        _ball.getGlobalBounds().intersects(_rightPaddle.getGlobalBounds()))
    {
        _ballVelocity.x = -_ballVelocity.x;
    }

    if (_ball.getPosition().y <= 0 || (_ball.getPosition().y + _ball.getRadius()) >= _windowSize.y)
    {
        _ballVelocity.y = -_ballVelocity.y;
    }

    if (_ball.getPosition().x <= 0 || (_ball.getPosition().x + _ball.getRadius()) >= _windowSize.x)
    {
        _ballVelocity.x = -_ballVelocity.x;
    }

    // fix it !!
}

void PvPGame::PvPModel::checkLeftCollision()
{
    if (_leftPaddle.getGlobalBounds().getPosition().y <= 0)
    {
        _leftVelocity.y = 0;
    }
}

void PvPGame::PvPModel::checkRightCollision()
{

}

void PvPGame::PvPModel::increaseRightScore()
{
    _rightScore++;
}
void PvPGame::PvPModel::increaseLeftScore()
{
    _leftScore++;

    // if (_leftScore == 3)
    //{
    //     // gameController( exitWindow(std::string playerName) )
    //     std::cout << "Left wins\n";
    // }
    // else if (_rightScore == 3)
    //{
    //     std::cout << "Right wins\n";
    // }
}

void PvPGame::PvPModel::moveLeftPaddle(float dir)
{
    _leftVelocity.y = _paddleSpeed * dir;
}

void PvPGame::PvPModel::moveRightPaddle(float dir)
{
    _rightVelocity.y = _paddleSpeed * dir;
}

void PvPGame::PvPModel::stopLeftPaddle()
{
    _leftVelocity.y = 0;
}

void PvPGame::PvPModel::stopRightPaddle()
{
    _rightVelocity.y = 0;
}

void PvPGame::PvPModel::updatePaddles(float &deltaTime)
{
    _leftPaddle.move(_leftVelocity * deltaTime);
    _rightPaddle.move(_rightVelocity * deltaTime);
}

int PvPGame::PvPModel::getLeftScore() const
{
    return _leftScore;
}

int PvPGame::PvPModel::getRightScore() const
{
    return _rightScore;
}

sf::Vector2u PvPGame::PvPModel::getWindowDimension() const
{
    return _windowSize;
}
