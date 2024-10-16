#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>

#include "GameStrategy.h"

#include "GlobalVaribles.h"

#include "Ball.h"
#include "PlayerMoveDownCommand.h"
#include "PlayerMoveUpCommand.h"
#include "Players.h"

class PvPMode : public GameStrategy
{
  private:
    Players *_leftPlayer;
    Players *_rightPlayer;

    PlayerMoveDownCommand *_moveDownCommand;
    PlayerMoveUpCommand *_moveUpCommand;

    sf::Clock _clock;

  private:
    void handlePlayerMovement(const sf::Keyboard::Key downKey, const sf::Keyboard::Key upKey, Players *player);

  public:
    PvPMode();
    ~PvPMode();

    static PvPMode &getInstance();

    void runStrategy(sf::RenderWindow &window) override;
};
