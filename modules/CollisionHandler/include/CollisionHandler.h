#pragma once
#include <SFML/Graphics.hpp>
#include <memory>

#include "Ball.h"
#include "GlobalVaribles.h"
#include "Players.h"

class CollisionHandler
{
  public:
    CollisionHandler();

    void upperPlayerCollision(Players *player);

    void lowerPlayerCollision(Players *player);

    static CollisionHandler &getInstance();

    void ballWindowYCollision(Ball *ball);

    int leftBallWindowCollision(Ball *ball);

    int rightBallWindowCollision(Ball* ball);

    void ballPlayersCollision(Ball *ball, Players *leftPlayer, Players *rightPlayer);
};
