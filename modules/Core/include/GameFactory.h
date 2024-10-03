#pragma once
#include <iostream>
#include <memory>
#include <string>

#include "BotMode.h"
#include "GameStrategy.h"
#include "GlobalVaribles.h"
#include "PvPMode.h"

class GameFactory
{
  private:
    sf::RenderWindow &_factoryWindow;

  public:
    GameFactory(sf::RenderWindow &window);

    void createGameMode(GameMode mode);
};
