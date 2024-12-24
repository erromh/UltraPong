#if __has_include("ExitWindow.h")
#include "ExitWindow.h"
#endif

ExitWindow::ExitWindow()
{
    _exitWindow.setSize(sf::Vector2f(EXITWINWIDTH, EXITWINHEIGHT));
    _exitWindow.setFillColor(sf::Color::White);
    _exitWindow.setPosition(EXITWINXPOS, EXITWINYPOS);
}

sf::RectangleShape ExitWindow::getShape()
{
    return _exitWindow;
}
