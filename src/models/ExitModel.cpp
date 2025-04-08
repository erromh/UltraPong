#include "ExitModel.h"

Exit::Model::Model()
{
    _menuItems = {"Play again", "Go to menu", "Quit the game"};
}

void Exit::Model::moveUp()
{
    _currentIndex = (_currentIndex > 0) ? _currentIndex - 1 : _menuItems.size() - 1;
}

void Exit::Model::moveDown()
{
    _currentIndex = (_currentIndex + 1) % _menuItems.size();
}

int Exit::Model::getCurrentIndex() const
{
    return _currentIndex;
}

std::string Exit::Model::getSelectedOption() const
{
    return _menuItems[_currentIndex];
}

const std::vector<std::string> &Exit::Model::getMenuItems() const
{
    return _menuItems;
}
