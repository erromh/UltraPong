#include "MenuView.h"

Menu::MenuView::MenuView()
{
    if (!loadResources())
    {
        throw std::runtime_error("Failed to load resources!");
    }
}

bool Menu::MenuView::loadResources()
{
    _isResLoaded = true;

    if (!_font.loadFromFile(_fontPath) || !_icon.loadFromFile(_iconPath))
    {
        std::cerr << "Can't find resources\n";
        _isResLoaded = false;
    }

    /*if (!_icon.loadFromFile(_iconPath))
    {
        std::cerr << "can't find icon\n";
        _isresloaded = false;
    }*/

    return _isResLoaded;
}

void Menu::MenuView::update(const MenuModel &model)
{
    _menuText.clear();

    _title.setFont(_font);
    _title.setString("Ultra Pong");
    _title.setCharacterSize(90);
    _title.setFillColor(sf::Color::White);
    _title.setPosition(120.f, 70.f);

    const auto &options = model.getOptions();

    for (size_t i = 0; i < options.size(); ++i)
    {
        sf::Text text;
        text.setFont(_font);
        text.setString(options[i]);
        text.setCharacterSize(60);
        text.setPosition(120.f, 250.f + i * 145);
        text.setFillColor(i == model.getSelectedIndex() ? sf::Color(0, 139, 139) : sf::Color::White);
        _menuText.push_back(text);
    }
}

void Menu::MenuView::draw(sf::RenderWindow &window)
{
    window.draw(_title);

    for (const auto &text : _menuText)
    {
        window.draw(text);
    }
}
