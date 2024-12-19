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

    void upperPlayerCollision(std::unique_ptr<Players> &player);

    void lowerPlayerCollision(std::unique_ptr<Players> &player);

    static CollisionHandler &getInstance();

    void ballWindowCollision(std::unique_ptr<Ball> &ball);

    void ballPlayersCollision(std::unique_ptr<Ball> &ball, std::unique_ptr<Players> &leftPlayer,
                              std::unique_ptr<Players> &rightPlayer);
};
