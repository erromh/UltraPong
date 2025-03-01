#include "PvPController.h"

PvPGame::PvPController::PvPController(PvPModel &model, PvPView &view) : _pvpModel(model), _pvpView(view)
{
}

void PvPGame::PvPController::handleInput(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        std::cout << "Enter was pressed in pvp controller\n";
    }
}

void PvPGame::PvPController::update()
{
    _pvpModel.updateBall();
    _pvpModel.checkCollision();
}

void PvPGame::PvPController::draw(sf::RenderWindow &window)
{
    _pvpView.render(window);
}

void PvPGame::PvPController::handleEvent(sf::Event &event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        if (event.key.code == sf::Keyboard::W)
        {
            _pvpModel._leftPaddle.move(0, -10);
        }

        if (event.key.code == sf::Keyboard::S)
        {
            _pvpModel._leftPaddle.move(0, 10);
        }
    }
}
