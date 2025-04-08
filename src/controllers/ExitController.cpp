#include "ExitController.h"

Exit::Controller::Controller(sf::RenderWindow &window) : _view(window, _model)
{
}

void Exit::Controller::draw(sf::RenderWindow &window)
{
    _view.draw(window);
}

void Exit::Controller::updateView()
{
    _view.update(_model);
}

void Exit::Controller::handleEvent(sf::Event &event, sf::RenderWindow &window)
{
    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::W)
        {
            _model.moveUp();
        }

        else if (event.key.code == sf::Keyboard::Down || event.key.code == sf::Keyboard::S)
        {
            _model.moveDown();
        }

        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Enter)
        {
            std::string option = _model.getSelectedOption();

            if (option == "Play again")
            {
                Controllers::GameController::getInstance()->setState(std::make_unique<PvPGame::PvPState>(window));
            }
            else if (option == "Go to menu")
            {
                std::cout << "Go to menu\n";
                Controllers::GameController::getInstance()->setState(std::make_unique<Menu::MenuState>(window));
            }
            else if (option == "Quit the game")
            {
                window.close();
            }
        }
    }
}
