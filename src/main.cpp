#include <SFML/Graphics.hpp>
#include <iostream>

#include "Ball/Ball.h"

//

int main()
{
    sf::RenderWindow win(sf::VideoMode(700, 700), "Ultra Pong", sf::Style::Default);

    sf::Color color(0, 0, 255);

    float x = 300, y = 100;

    Ball ball1(15, x, y);

    while (win.isOpen())
    {
        sf::Event event;

        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                win.close();
        }

        win.clear(color);
        win.draw(ball1.getShape());
        win.display();
    }

    return 0;
}
