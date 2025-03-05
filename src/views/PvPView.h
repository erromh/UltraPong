#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "PvPModel.h"

namespace PvPGame
{
class PvPView
{
  private:
    PvPModel &_PvPModel;

    sf::Text _leftScore;
    sf::Text _rightScore;

    std::string _fontPath = std::string(PROJECT_ROOT_DIR) + "/resources/Fonts/Minecraft.ttf";
    sf::Font _font;

    sf::Vector2u _windowSize;

  public:
    PvPView(PvPModel &model, sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    void updateLeftScoreText();
    void updateRigthScoreText();
};
} // namespace PvPGame
