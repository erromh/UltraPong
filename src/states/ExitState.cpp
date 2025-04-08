#include "ExitState.h"

Exit::State::State(sf::RenderWindow &window) : _window(window), _view(window, _model), _controller(window)
{
}

void Exit::State::handleEvent(sf::Event &event)
{
    _controller.handleEvent(event, _window);
}

void Exit::State::handleInput(sf::RenderWindow &window)
{
}

void Exit::State::render(sf::RenderWindow &window)
{
    _controller.draw(window);
}

void Exit::State::update(float deltatime)
{
    _controller.updateView();
}
