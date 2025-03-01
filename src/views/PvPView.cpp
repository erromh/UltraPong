#include "PvPView.h"

PvPGame::PvPView::PvPView(PvPModel &model) : _PvPModel(model)
{
}

void PvPGame::PvPView::render(sf::RenderWindow &window)
{
    window.draw(_PvPModel._ball);
    window.draw(_PvPModel._leftPaddle);
    window.draw(_PvPModel._rightPaddle);
}
