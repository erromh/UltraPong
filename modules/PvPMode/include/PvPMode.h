#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameStrategy.h"

#include "Ball.h"
#include "PlayerMoveDownCommand.h"
#include "PlayerMoveUpCommand.h"
#include "Players.h"

class PvPMode : public GameStrategy
{
  private:
    Players *_leftPlayer;

    PlayerMoveDownCommand *_moveDownCommand;

    PlayerMoveUpCommand *_moveUpCommand;

  public:
    PvPMode();
    ~PvPMode();

    static PvPMode &getInstance();

    void runStrategy(sf::RenderWindow &window) override;
};
