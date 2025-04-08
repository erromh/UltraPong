#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

namespace Exit
{
class Model
{
  private:
    std::vector<std::string> _menuItems;
    int _currentIndex = 0;

  public:
    Model();

  public:
    void moveUp();
    void moveDown();

    int getCurrentIndex() const;
    const std::vector<std::string> &getMenuItems() const;
    std::string getSelectedOption() const;
};
} // namespace Exit
