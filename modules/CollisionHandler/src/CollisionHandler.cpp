#define ballPosition ball.get()->getPosition()
#define ballShape ball.get()->getShape()
#define leftplayerShape leftPlayer.get()->getPlayerShape()
#define rightPlayerShape rightPlayer.get()->getPlayerShape()

#include "CollisionHandler.h"

CollisionHandler::CollisionHandler()
{
}

CollisionHandler &CollisionHandler::getInstance()
{
    static CollisionHandler instance;
    return instance;
}

void CollisionHandler::upperPlayerCollision(std::unique_ptr<Players> &player)
{
    // Check for collision with upper boundary

    if (player->getPlayerShape().getPosition().y <= 0)
    {
        player->stopMoving();
    }
}

void CollisionHandler::lowerPlayerCollision(std::unique_ptr<Players> &player)
{
    // Check for collision with lower boundary

    if ((player->getPlayerShape().getPosition().y + PLAYERSIZEY) >= WINHEIGHT)
    {
        player->stopMoving();
    }
}

void CollisionHandler::ballWindowCollision(std::unique_ptr<Ball> &ball)
{
    // Check for collision with window bounbary

    if ((ballPosition.y + ballShape.getRadius()) >= WINHEIGHT || ballPosition.y <= 0)
    {
        ball.get()->changeYDirection();
    }

    if ((ballPosition.x + ballShape.getRadius()) >= WINWIDTH || ballPosition.x <= 0)
    {
        ball.get()->changeXDirection();
    }
}

void CollisionHandler::ballPlayersCollision(std::unique_ptr<Ball> &ball, std::unique_ptr<Players> &leftPlayer,
                                            std::unique_ptr<Players> &rightPlayer)
{
    // Check for collision with players

    if (leftplayerShape.getGlobalBounds().intersects(ballShape.getGlobalBounds()))
    {
        ball.get()->changeXDirection();
    }

    if (rightPlayerShape.getGlobalBounds().intersects(ballShape.getGlobalBounds()))
    {
        ball.get()->changeXDirection();
    }
}
