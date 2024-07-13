#include <SFML/Graphics.hpp>
#include <iostream>

#include "MoveSquare.h"

// cmake-cookbook/chapter-07/recipe-07

int main()
{
    sf::RenderWindow win(sf::VideoMode(700, 700), "Ultra Pong", sf::Style::Default);

    sf::Color color(0, 0, 255);

    double x = 300, y = 100;

    MoveSquare item1(x, y);

    while (win.isOpen())
    {
        sf::Event event;

        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                item1.moveItem();
            }
        }

        item1.moveItem();

        win.clear(color);
        win.draw(item1.getItem());
        win.display();
    }

    return 0;
}
