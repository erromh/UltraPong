#pragma once
#include <SFML/Graphics.hpp>

#include "GlobalVaribles.h"
#include "Players.h"

class CollisionHandler
{
  public:
    CollisionHandler();

    void upperPlayerCollision(Players *player);

    void lowerPlayerCollision(Players* player);

    static CollisionHandler &getInstance();

    // void ballWindowCollision();
};
