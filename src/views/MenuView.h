#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

#include "MenuModel.h"

namespace Menu
{
class MenuView
{
  private:
    sf::Font _font;
    std::vector<sf::Text> _menuText;
    sf::Text _title;
    std::string _fontPath = std::string(PROJECT_ROOT_DIR) + "/resources/Fonts/Minecraft.ttf";

    sf::Image _icon;
    std::string _iconPath = std::string(PROJECT_ROOT_DIR) + "/resources/Icons/apps.png";

    bool _isResLoaded;

    sf::Vector2u _windowSize;

  private:
    bool loadResources();

  public:
    MenuView(sf::RenderWindow &window);
    void update(const MenuModel &model);
    void draw(sf::RenderWindow &window);
};
} // namespace Menu
