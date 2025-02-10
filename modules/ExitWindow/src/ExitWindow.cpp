#if __has_include("ExitWindow.h")
#include "ExitWindow.h"
#endif

ExitWindow::ExitWindow()
{
    if (!_font.loadFromFile(_fontPath))
    {
        throw std::runtime_error("Failed to load font\n");
    }

    _exitWindow.setSize(sf::Vector2f(EXITWINWIDTH, EXITWINHEIGHT));
    _exitWindow.setFillColor(sf::Color::White);
    _exitWindow.setPosition(EXITWINXPOS, EXITWINYPOS);

    _title.setFont(_font);
    _title.setString("Game over");
    _title.setCharacterSize(60);
    _title.setFillColor(_fontColor);
    _title.setPosition(EXITWINXPOS + 50, EXITWINYPOS + 10);

    _options[0].setFont(_font);
    _options[0].setString("Play again");
    _options[0].setCharacterSize(40);
    _options[0].setFillColor(_fontColor);
    _options[0].setPosition(EXITWINXPOS + 50, EXITWINYPOS + 120);

    _options[1].setFont(_font);
    _options[1].setString("Go to menu");
    _options[1].setCharacterSize(40);
    _options[1].setFillColor(_fontColor);
    _options[1].setPosition(EXITWINXPOS + 50, EXITWINYPOS + 200);

    _options[2].setFont(_font);
    _options[2].setString("Exit");
    _options[2].setCharacterSize(40);
    _options[2].setFillColor(_fontColor);
    _options[2].setPosition(EXITWINXPOS + 50, EXITWINYPOS + 300);
}

int ExitWindow::selectedItem()
{
    return _selectedItem;
}

void ExitWindow::showWindow(sf::RenderWindow &window)
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
    }

    window.draw(_exitWindow);

    drawOptions(window);
}

void ExitWindow::drawOptions(sf::RenderWindow &window)
{
    window.draw(_title);

    for (int i = 0; i < _options.size(); i++)
    {
        window.draw(_options[i]);
    }
}

sf::RectangleShape ExitWindow::getShape()
{
    return _exitWindow;
}
