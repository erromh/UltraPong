#include "ExitView.h"

Exit::View::View(sf::RenderWindow &window, Model &model) : _model(model)
{
    if (!_font.loadFromFile(_fontPath))
    {
        throw std::runtime_error("Failed to load resources!");
    }

    _windowSize = window.getSize();
}

void Exit::View::update(const Model &model)
{
    _textItems.clear();

    int offsetY = 200;

    const auto &items = _model.getMenuItems();

    float characterSize = (_windowSize.y / 12.0);
    float xPosition = (_windowSize.x / 4.0);

    for (size_t i = 0; i < items.size(); ++i)
    {
        sf::Text text;
        text.setFont(_font);
        text.setString(items[i]);
        text.setCharacterSize(characterSize);
        text.setFillColor(i == model.getCurrentIndex() ? sf::Color::Blue : sf::Color::White);
        text.setPosition(xPosition, offsetY);
        offsetY += 150;

        _textItems.push_back(text);
    }
}

void Exit::View::draw(sf::RenderWindow &window)
{
    for (const auto &text : _textItems)
    {
        window.draw(text);
    }
}
