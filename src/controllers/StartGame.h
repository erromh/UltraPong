#pragma once
#include <SFML/Graphics.hpp>

#include "GameController.h"
#include "MenuState.h"

namespace Start
{
class StartGame
{
  private:
    static StartGame *_instance;
    sf::Image _icon;
    std::string _iconPath = std::string(PROJECT_ROOT_DIR) + "/resources/Icons/apps.png";

  protected:
    StartGame();
    ~StartGame();
    StartGame(StartGame &obj) = delete;

  public:
    void operator=(const StartGame &) = delete;
    static StartGame *getInstatnce();
    void startingGame();
};
} // namespace Start
