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
