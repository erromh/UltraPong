#pragma once
#include <SFML/Graphics.hpp>

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

enum PlayerData
{
    LEFTPLAYERXCOORDINATE = (WINWIDTH / 50),

    // Fix it !!
    LEFTPLAYERYCOORDINATE = (WINHEIGHT / 3),

    RIGHTPLAYERXCOORDINATE = (WINWIDTH - LEFTPLAYERXCOORDINATE * 2),

    // Also fix it
    RIGHTPLAYERYCOORDINATE = (WINHEIGHT / 3)
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
