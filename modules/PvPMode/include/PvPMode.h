#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <memory>

#include "GlobalVaribles.h"

#include "Ball.h"
#include "CollisionHandler.h"
#include "GameStrategy.h"
#include "PlayerMoveDownCommand.h"
#include "PlayerMoveUpCommand.h"
#include "Players.h"

class PvPMode : public GameStrategy
{
  private:
    std::unique_ptr<Players> _leftPlayer;
    std::unique_ptr<Players> _rightPlayer;

    PlayerMoveDownCommand *_moveDownCommand;
    PlayerMoveUpCommand *_moveUpCommand;

    sf::Clock _clock;

    std::unique_ptr<Ball> _ball;

  private:
    void handlePlayerMovement(const sf::Keyboard::Key downKey, const sf::Keyboard::Key upKey,
                              std::unique_ptr<Players> &player);

    void updateEntity(float &deltatime);

  public:
    PvPMode();
    ~PvPMode();

    static PvPMode &getInstance();

    void runStrategy(sf::RenderWindow &window) override;
};
