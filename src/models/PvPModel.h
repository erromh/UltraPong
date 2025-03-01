#pragma once
#include <SFML/Graphics.hpp>

namespace PvPGame
{
class PvPModel
{
  private:
    sf::Vector2f _ballVelocity;

    int _leftScore = 0;
    int _rightScore = 0;

  public:
    sf::CircleShape _ball;
    sf::RectangleShape _leftPaddle;
    sf::RectangleShape _rightPaddle;

    PvPModel();

    void resetGame();
    void updateBall();
    void checkCollision();

    int getLeftScore() const;
    int getRightScore() const;
};
} // namespace PvPGame
