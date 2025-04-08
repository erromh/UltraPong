#pragma once
#include <iostream>
#include <string>
#include <vector>

namespace Menu
{
class MenuModel
{
  private:
    std::vector<std::string> _options;
    int _selectedIndex = 0;

  public:
    MenuModel();

    void moveUp();
    void moveDown();
    int getSelectedIndex() const;
    std::string getSelectedOption() const;
    const std::vector<std::string> &getOptions() const;
};
} // namespace Menu
