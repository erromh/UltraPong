#include "GameMenu.h"

GameMenu::GameMenu(sf::RenderWindow &window) : _window(window)
{
    if (!_font.loadFromFile(_fontPath))
    {
        throw std::runtime_error("Failed to load font\n");
    }

    yCoordinate = MENUYCOORDINATE;

    _title.setFont(_font);
    _title.setString("Ultra Pong");
    _title.setCharacterSize(TITLESIZE);
    _title.setFillColor(sf::Color::White);
    _title.setPosition(MENUXCOORDINATE, yCoordinate);

    _options[0].setFont(_font);
    _options[0].setString("PvP Game");
    _options[0].setCharacterSize(ITEMSIZE);
    _options[0].setFillColor(sf::Color::White);
    _options[0].setPosition(MENUXCOORDINATE, (yCoordinate += TITLEITEMDIST));

    _options[1].setFont(_font);
    _options[1].setString("Bot game");
    _options[1].setCharacterSize(ITEMSIZE);
    _options[1].setFillColor(sf::Color::White);
    _options[1].setPosition(MENUXCOORDINATE, (yCoordinate += ITEMDIST));

    _options[2].setFont(_font);
    _options[2].setString("Network game");
    _options[2].setCharacterSize(ITEMSIZE);
    _options[2].setFillColor(sf::Color::White);
    _options[2].setPosition(MENUXCOORDINATE, (yCoordinate += ITEMDIST));

    _options[3].setFont(_font);
    _options[3].setString("Exit");
    _options[3].setCharacterSize(ITEMSIZE);
    _options[3].setFillColor(sf::Color::White);
    _options[3].setPosition(MENUXCOORDINATE, (yCoordinate += ITEMDIST));
}

int GameMenu::getSelectedMenuItem()
{
    return _menuSelect;
}

void GameMenu::drawItems()
{
    _window.draw(_title);

    for (int i = 0; i < 4; i++)
    {
        _window.draw(_options[i]);
    }
}

void GameMenu::moveDown()
{
    std::cout << "moveDown() _menuSelect = " << _menuSelect << '\n';

    _menuSelect++;

    if (_menuSelect < 4)
    {
        _options[_menuSelect - 1].setFillColor(menuTextColor);
        _options[_menuSelect].setFillColor(choseTextColor);
    }
    else
    {
        _options[_menuSelect - 1].setFillColor(menuTextColor);
        _menuSelect = 0;
        _options[_menuSelect].setFillColor(choseTextColor);
    }
}

void GameMenu::moveUp()
{
    std::cout << "moveUp() _menuSelect = " << _menuSelect << '\n';

    _menuSelect--;

    if (_menuSelect >= 0)
    {
        _options[_menuSelect].setFillColor(choseTextColor);
        _options[_menuSelect + 1].setFillColor(menuTextColor);
    }
    else
    {
        _options[0].setFillColor(menuTextColor);
        _menuSelect = 3;
        _options[_menuSelect].setFillColor(choseTextColor);
    }
}
