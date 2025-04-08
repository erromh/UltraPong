#include "MenuController.h"
#include "GameController.h"
#include "PvPState.h"

Menu::MenuController::MenuController(sf::RenderWindow &window) : _view(window)
{
}

void Menu::MenuController::handleInput(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        if (_model.getSelectedOption() == "PvP game")
        {
            Controllers::GameController::getInstance()->setState(std::make_unique<PvPGame::PvPState>(window));
        }
        else if (_model.getSelectedOption() == "Bot game")
        {
            std::cout << "Bot mode is working\n";
        }
        else if (_model.getSelectedOption() == "Network mode")
        {
            std::cout << "Network is working\n";
        }
        else if (_model.getSelectedOption() == "Exit")
        {
            window.close();
        }
    }
}

void Menu::MenuController::updateView()
{
    _view.update(_model);
}

void Menu::MenuController::draw(sf::RenderWindow &window)
{
    _view.draw(window);
}

void Menu::MenuController::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyReleased &&
        (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W))
    {
        _model.moveUp();
    }

    else if (event.type == sf::Event::KeyReleased &&
             (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S))
    {
        _model.moveDown();
    }
}

// std::string Menu::MenuController::getSelectedOption() const
//{
//     return _model.getSelectedOption();
// }
