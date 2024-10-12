#pragma once
#include <SFML/Graphics.hpp>

// const int w = sf::VideoMode::getDesktopMode().width;

enum WindowSize
{
    WINWIDTH = 1700,
    WINHEIGHT = 900
};

enum BallData
{
    BALLXCOORDINATE = (WINWIDTH / 2),
    BALLYCOORDINATE = (WINHEIGHT / 2)
};

enum MenuItemsCoordinate
{
    MENUXCOORDINATE = (WINWIDTH / 10),
    MENUYCOORDINATE = (WINHEIGHT / 10),

    TITLESIZE = MENUYCOORDINATE,
    TITLEITEMDIST = (WINHEIGHT / 5),

    ITEMSIZE = (WINHEIGHT / 15),
    ITEMDIST = (WINHEIGHT / 6)
};

enum class GameMode
{
    PvP,
    Bot,
    Net
};

enum Themes
{
    Light,
    Dark
};

// sf::Color menuTextColorLight = sf::Color::White;
// sf::Color menuTextColorDark = sf::Color::Black;

// enum class GameColors
//{
//     ,
// s    dss = sf::Color::Black
// };
