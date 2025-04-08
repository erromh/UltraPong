#include "MenuView.h"

Menu::MenuView::MenuView(sf::RenderWindow &window)
{
    if (!loadResources())
    {
        throw std::runtime_error("Failed to load resources!");
    }

    _windowSize = window.getSize();
}

bool Menu::MenuView::loadResources()
{
    _isResLoaded = true;

    if (!_font.loadFromFile(_fontPath) || !_icon.loadFromFile(_iconPath))
    {
        std::cerr << "Can't find resources\n";
        _isResLoaded = false;
    }

    return _isResLoaded;
}

void Menu::MenuView::update(const MenuModel &model)
{
    _menuText.clear();

    float titleCharacterSise = (_windowSize.y * 0.11f);
    float titleYPos = (_windowSize.y * 0.08f);
    float optionsCharacterSise = (_windowSize.y * 0.08f);
    float optionsXPos = (_windowSize.x * 0.09f);
    float optionsFirstYPos = (_windowSize.x / 6.8);
    float optionsSecondYPos = (_windowSize.y / 6.0);

    _title.setFont(_font);
    _title.setString("Ultra Pong");
    _title.setCharacterSize(titleCharacterSise);
    _title.setFillColor(sf::Color::White);
    _title.setPosition(optionsXPos, titleYPos);

    const auto &options = model.getOptions();

    for (size_t i = 0; i < options.size(); ++i)
    {
        sf::Text text;
        text.setFont(_font);
        text.setString(options[i]);
        text.setCharacterSize(optionsCharacterSise);
        text.setPosition(optionsXPos, optionsFirstYPos + i * optionsSecondYPos);
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
