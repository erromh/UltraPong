#pragma once
#include <SFML/Graphics.hpp>
#include <array>

#include "GlobalVaribles.h"

class ExitWindow
{
  public:
    ExitWindow();

    sf::RectangleShape getShape();

    void showWindow(sf::RenderWindow &window);

    int selectedItem();

    void moveUp();

    void moveDown();

    void drawOptions(sf::RenderWindow &window);

  private:
    sf::RectangleShape _exitWindow;

    std::string _fontPath = std::string(PROJECT_ROOT_DIR) + "/resources/Fonts/Minecraft.ttf";

    sf::Font _font;

    sf::Text _title;

    std::array<sf::Text, 3> _options; // Play again, Go to menu, Exit.

    sf::Color _fontColor = sf::Color::Blue;

    int _selectedItem = -1;
};
