#include "PvPState.h"

PvPGame::PvPState::PvPState() : _view(_model), _controller(_model, _view)
{
}

void PvPGame::PvPState::handleInput(sf::RenderWindow &window)
{
    _controller.handleInput(window);
}

void PvPGame::PvPState::update(float deltaTime)
{
    _controller.update();
}

void PvPGame::PvPState::render(sf::RenderWindow &window)
{
    _view.render(window);
}

void PvPGame::PvPState::handleEvent(sf::Event &event)
{
    _controller.handleEvent(event);
}
