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

void CollisionHandler::ballWindowCollision(std::unique_ptr<Ball> &ball)
{
    if ((ball.get()->getPosition().y + ball.get()->getShape().getRadius()) >= WINHEIGHT ||
        ball.get()->getPosition().y <= 0)
    {
        std::cout << "Ball collision y\n";
        ball.get()->changeYDirection();
    }

    if ((ball.get()->getPosition().x + ball.get()->getShape().getRadius()) >= WINWIDTH || ball.get()->getPosition().x <= 0)
    {
        std::cout << "Ball collision x\n";
        ball.get()->changeXDirection();
    }
}
