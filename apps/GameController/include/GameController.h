#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <string>
#include <unordered_map>

#include "GameFactory.h"
#include "GameMenu.h"
#include "GlobalVaribles.h"

class GameController
{
  private:
    sf::RenderWindow &_mainWindow;
    std::unique_ptr<GameMenu> _menu;
    std::unique_ptr<GameFactory> _gameFactory;

    std::unordered_map<int, GameMode> _gameMap = {{0, GameMode::PvP}, {1, GameMode::Bot}, {2, GameMode::Net}};

    bool currentTheme = 0;

    std::string _iconPath = std::string(PROJECT_ROOT_DIR) + "/resources/Icons/apps.png";
    sf::Image _icon;

  private:
    void handleEvents(bool &needsRedraw);

    void changeTheme();

  public:
    GameController(sf::RenderWindow &window);

    void startMenu();
};
