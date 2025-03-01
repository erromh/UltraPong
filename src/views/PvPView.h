#pragma once
#include <SFML/Graphics.hpp>

#include "PvPModel.h"

namespace PvPGame
{
class PvPView
{
  private:
    PvPModel &_PvPModel;

  public:
    PvPView(PvPModel &model);
    void render(sf::RenderWindow &window);
};
} // namespace PvPGame
