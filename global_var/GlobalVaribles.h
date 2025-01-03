#pragma once
#include <SFML/Graphics.hpp>

enum WindowSize
{
    WINWIDTH = 1700,
    WINHEIGHT = 900
};

enum ExitWindowSize
{
    EXITWINWIDTH = (WINWIDTH / 2),
    EXITWINHEIGHT = (WINHEIGHT / 2),

    EXITWINXPOS = ((WINWIDTH / 2) - (EXITWINWIDTH / 2)),
    EXITWINYPOS = ((WINHEIGHT / 2) - (EXITWINHEIGHT / 2))
};

enum BallData
{
    BALLXCOORDINATE = (WINWIDTH / 2),
    BALLYCOORDINATE = (WINHEIGHT / 2),

    BALLRADIUS = (WINHEIGHT / 60)
};

enum PlayerData
{
    LEFTPLAYERXCOORDINATE = (WINWIDTH / 50),

    // Fix it !!
    LEFTPLAYERYCOORDINATE = (WINHEIGHT / 3),

    RIGHTPLAYERXCOORDINATE = (WINWIDTH - LEFTPLAYERXCOORDINATE * 2),

    // Also fix it
    RIGHTPLAYERYCOORDINATE = (WINHEIGHT / 3),

    PLAYERSIZEY = (WINHEIGHT / 6),
    PLAYERSIZEX = (WINHEIGHT / 30)
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
