#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "ExitModel.h"

namespace Exit
{
class View
{
  private:
    sf::Vector2u _windowSize;
    Model _model;
    std::vector<sf::Text> _textItems;
    sf::Font _font;
    std::string _fontPath = std::string(PROJECT_ROOT_DIR) + "/resources/Fonts/Minecraft.ttf";

  public:
    View(sf::RenderWindow &window, Model &model);
    void update(const Model &model);
    void draw(sf::RenderWindow &window);
};
} // namespace Exit
