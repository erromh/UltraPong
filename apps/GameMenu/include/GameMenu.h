#pragma once
#include <SFML/Graphics.hpp>
#include <filesystem>
#include <iostream>
#include <memory>
#include <string>

#include "GlobalVaribles.h"

class GameMenu
{
  public:
    GameMenu(sf::RenderWindow &window);

    void moveUp();
    void moveDown();
    void drawItems();

    int getSelectedMenuItem();

  private:
    sf::RenderWindow &_window;

    sf::Text _title;
    sf::Text _options[4];
    sf::Font _font;

    float yCoordinate;

    std::string _fontPath = std::string(PROJECT_ROOT_DIR) + "/resources/Fonts/Minecraft.ttf";

    int _menuSelect = -1;
    sf::Color menuTextColor = sf::Color::White;
    sf::Color choseTextColor = sf::Color(0, 139, 139);
};
