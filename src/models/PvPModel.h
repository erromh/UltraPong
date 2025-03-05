#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace PvPGame
{
class PvPModel
{
  private:
    sf::Vector2f _ballVelocity;
    sf::Vector2u _windowSize;

    int _leftScore = 0;
    int _rightScore = 0;

    sf::Vector2f _leftVelocity;
    sf::Vector2f _rightVelocity;
    float _paddleSpeed;

  public:
    sf::CircleShape _ball;
    sf::RectangleShape _leftPaddle;
    sf::RectangleShape _rightPaddle;

    PvPModel(sf::RenderWindow &window);

    void resetGame();
    void updateBall();
    void checkBallCollision();

    void checkLeftCollision();
    void checkRightCollision();

    int getLeftScore() const;
    int getRightScore() const;

    void moveLeftPaddle(float dir);
    void moveRightPaddle(float dir);

    void stopLeftPaddle();
    void stopRightPaddle();

    void increaseLeftScore();
    void increaseRightScore();

    void updatePaddles(float &deltaTime);

    sf::Vector2u getWindowDimension() const;
};
} // namespace PvPGame
