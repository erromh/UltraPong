#include "PvPController.h"

PvPGame::PvPController::PvPController(PvPModel &model, PvPView &view) : _pvpModel(model), _pvpView(view)
{
}

void PvPGame::PvPController::handleInput(sf::RenderWindow &window)
{
}

void PvPGame::PvPController::update(float &deltaTime)
{
    _pvpModel.updateBall();

    _pvpModel.checkBallCollision();

    _pvpModel.updatePaddles(deltaTime);

    if ((_pvpModel._ball.getPosition().x + _pvpModel._ball.getRadius()) >= _pvpModel.getWindowDimension().x)
    {
        _pvpModel.increaseLeftScore();
    }

    if (_pvpModel._ball.getPosition().x <= 0)
    {
        _pvpModel.increaseRightScore();
    }

    if (_pvpModel.getLeftScore() == 2)
    {
        // call exit window
        std::cout << "Left wins!\n";
    }
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
            _pvpModel.moveLeftPaddle(-1.f);
        }

        if (event.key.code == sf::Keyboard::S)
        {
            _pvpModel.moveLeftPaddle(1.f);
        }

        if (event.key.code == sf::Keyboard::Up)
        {
            _pvpModel.moveRightPaddle(-1.f);
        }

        if (event.key.code == sf::Keyboard::Down)
        {
            _pvpModel.moveRightPaddle(1.f);
        }
    }

    if (event.type == sf::Event::KeyReleased)
    {
        if (event.key.code == sf::Keyboard::W || event.key.code == sf::Keyboard::S)
        {
            _pvpModel.stopLeftPaddle();
        }

        if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down)
        {
            _pvpModel.stopRightPaddle();
        }
    }
}
