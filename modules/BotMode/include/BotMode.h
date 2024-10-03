#pragma once
#include <SFML/Graphics.hpp>

#include "GameStrategy.h"

class BotMode : public GameStrategy
{
  public:
    BotMode();

    void runStrategy(sf::RenderWindow &window) override;
};
