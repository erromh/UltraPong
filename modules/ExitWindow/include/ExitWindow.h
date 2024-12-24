#pragma once
#include <SFML/Graphics.hpp>

#include "GlobalVaribles.h"

class ExitWindow
{
  public:
    ExitWindow();

    sf::RectangleShape getShape();

  private:
    sf::RectangleShape _exitWindow;

    std::string _fontPath = std::string(PROJECT_ROOT_DIR) + "/resources/Fonts/Minecraft.ttf";
};
