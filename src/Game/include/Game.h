#pragma once
#include "GlobalVaribles.h"
#include "include/Ball.h"
#include "include/PlayerMoveDownCommand.h"
#include "include/PlayerMoveUpCommand.h"
#include "include/Players.h"

#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class Game
{
  private:
    std::unique_ptr<sf::RenderWindow> _gameWindow;

    std::unique_ptr<Ball> _gameBall;

  public:
    Game();

    void startGame();
};
