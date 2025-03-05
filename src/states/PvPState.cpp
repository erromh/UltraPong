#include "PvPState.h"

PvPGame::PvPState::PvPState(sf::RenderWindow &window)
    : _model(window), _view(_model, window), _controller(_model, _view)
{
}

void PvPGame::PvPState::handleInput(sf::RenderWindow &window)
{
    _controller.handleInput(window);
}

void PvPGame::PvPState::update(float deltaTime)
{
    _controller.update(deltaTime);


    _view.updateLeftScoreText();
    _view.updateRigthScoreText();
}

void PvPGame::PvPState::render(sf::RenderWindow &window)
{
    _view.render(window);
}

void PvPGame::PvPState::handleEvent(sf::Event &event)
{
    _controller.handleEvent(event);
}
