#define ballPosition ball->getPosition()
#define ballShape ball->getShape()
#define leftplayerShape leftPlayer->getPlayerShape()
#define rightPlayerShape rightPlayer->getPlayerShape()

#include "CollisionHandler.h"

CollisionHandler::CollisionHandler()
{
}

CollisionHandler &CollisionHandler::getInstance()
{
    static CollisionHandler instance;
    return instance;
}

void CollisionHandler::upperPlayerCollision(Players *player)
{
    // Check for collision with upper boundary

    if (player->getPlayerShape().getPosition().y <= 0)
    {
        player->stopMoving();
    }
}

void CollisionHandler::lowerPlayerCollision(Players *player)
{
    // Check for collision with lower boundary

    if ((player->getPlayerShape().getPosition().y + PLAYERSIZEY) >= WINHEIGHT)
    {
        player->stopMoving();
    }
}

void CollisionHandler::ballWindowCollision(Ball *ball)
{
    // Check for collision with window bounbary

    if ((ballPosition.y + ballShape.getRadius()) >= WINHEIGHT || ballPosition.y <= 0)
    {
        ball->changeYDirection();
    }

    if ((ballPosition.x + ballShape.getRadius()) >= WINWIDTH || ballPosition.x <= 0)
    {
        ball->changeXDirection();
    }
}

void CollisionHandler::ballPlayersCollision(Ball *ball, Players *leftPlayer, Players *rightPlayer)
{
    // Check for collision with players

    if (leftplayerShape.getGlobalBounds().intersects(ballShape.getGlobalBounds()))
    {
        ball->changeXDirection();
    }

    if (rightPlayerShape.getGlobalBounds().intersects(ballShape.getGlobalBounds()))
    {
        ball->changeXDirection();
    }
}
