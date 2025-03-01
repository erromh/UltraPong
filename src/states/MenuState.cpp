#include "MenuState.h"

void Menu::MenuState::handleInput(sf::RenderWindow &window)
{
    _menuController.handleInput(window);
}

void Menu::MenuState::update(float deltaTime)
{
     _menuController.updateView();
}

void Menu::MenuState::render(sf::RenderWindow &window)
{
    _menuController.draw(window);
}

void Menu::MenuState::handleEvent(sf::Event &event)
{
    _menuController.handleEvent(event);
}
