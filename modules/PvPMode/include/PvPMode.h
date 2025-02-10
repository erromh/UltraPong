#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <map>
#include <memory>

#include "GlobalVaribles.h"

#include "Ball.h"
#include "CollisionHandler.h"
#include "ExitWindow.h"
#include "GameStrategy.h"
#include "PlayerMoveDownCommand.h"
#include "PlayerMoveUpCommand.h"
#include "Players.h"

class PvPMode : public GameStrategy
{
  private:
    std::unique_ptr<Players> _leftPlayer;
    std::unique_ptr<Players> _rightPlayer;

    std::unique_ptr<Ball> _ball;
    std::unique_ptr<ExitWindow> _exitWindow;

    PlayerMoveDownCommand *_moveDownCommand;
    PlayerMoveUpCommand *_moveUpCommand;

    sf::Clock _clock;

    int leftPlayerCount = 0;
    int rightPlayerCount = 0;

    sf::Font _font;
    std::string _fontPath = std::string(PROJECT_ROOT_DIR) + "/resources/Fonts/Minecraft.ttf";

    sf::Text _rightPlayerCount;
    sf::Text _leftPlayerCount;

  private:
    void handlePlayerMovement(const sf::Keyboard::Key downKey, const sf::Keyboard::Key upKey, Players *player);

    void updateEntity();

    void initializeWindow(sf::RenderWindow &window);

    void processEvents(sf::RenderWindow &window);

    void collisionsHandler();

    void render(sf::RenderWindow &window);

    void initializeEntity();

    void handleExeption(const std::exception &e);

    int checkWinner();

    void showExitWindow(sf::RenderWindow &window);

  public:
    PvPMode();
    ~PvPMode();

    static PvPMode &getInstance();

    void runStrategy(sf::RenderWindow &window) override;
};
