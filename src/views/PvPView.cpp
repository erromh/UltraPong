#include "PvPView.h"

PvPGame::PvPView::PvPView(PvPModel &model, sf::RenderWindow &window) : _PvPModel(model)
{
    if (!_font.loadFromFile(_fontPath))
    {
        throw std::runtime_error("Failed to load resources!");
    }

    _windowSize = window.getSize();

    int characterSize = (_windowSize.y / 9);

    float leftXCoordinate = (_windowSize.x / 2.5);
    float rightXCoordinate = (_windowSize.x - leftXCoordinate) - characterSize;
    float scoteTextYCoordinate = (_windowSize.y / 10.0);

    _leftScore.setFont(_font);
    _leftScore.setString("0");
    _leftScore.setCharacterSize(characterSize);
    _leftScore.setFillColor(sf::Color::White);
    _leftScore.setPosition(leftXCoordinate, scoteTextYCoordinate);

    _rightScore.setFont(_font);
    _rightScore.setString("0");
    _rightScore.setCharacterSize(characterSize);
    _rightScore.setFillColor(sf::Color::White);
    _rightScore.setPosition(rightXCoordinate, scoteTextYCoordinate);
}

void PvPGame::PvPView::updateLeftScoreText()
{
    _leftScore.setString(std::to_string(_PvPModel.getLeftScore()));
}

void PvPGame::PvPView::updateRigthScoreText()
{
    _rightScore.setString(std::to_string(_PvPModel.getRightScore()));
}

void PvPGame::PvPView::render(sf::RenderWindow &window)
{
    window.draw(_PvPModel._ball);
    window.draw(_PvPModel._leftPaddle);
    window.draw(_PvPModel._rightPaddle);

    window.draw(_rightScore);
    window.draw(_leftScore);
}
