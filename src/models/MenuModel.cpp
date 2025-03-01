#include "MenuModel.h"

Menu::MenuModel::MenuModel()
{
    _options = {"PvP game", "Bot game", "Network mode", "Exit"};
}

void Menu::MenuModel::moveDown()
{
    _selectedIndex = (_selectedIndex < _options.size() - 1) ? _selectedIndex + 1 : 0;
}

void Menu::MenuModel::moveUp()
{
    _selectedIndex = (_selectedIndex > 0) ? _selectedIndex - 1 : _options.size() - 1;
}

int Menu::MenuModel::getSelectedIndex() const
{
    return _selectedIndex;
}

std::string Menu::MenuModel::getSelectedOption() const
{
    return _options[_selectedIndex];
}

const std::vector<std::string> &Menu::MenuModel::getOptions() const
{
    return _options;
}
