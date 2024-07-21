#include "GlobalVaribles.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Ball/include/Ball.h"
#include "Players/include/Players.h"

int main()
{
    sf::RenderWindow win(sf::VideoMode(1700, 900), "Ultra Pong", sf::Style::Default);

    sf::Color color(0, 0, 255);

    float ballX = 300, ballY = 100;
    float plX = 0, plY = 350;

    Ball ball1(15, ballX, ballY);
    Players palyer1(plX, plY);

    while (win.isOpen())
    {
        sf::Event event;

        while (win.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                win.close();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                win.close();
            }
        }

        win.clear(color);
        win.draw(ball1.getShape());
        win.draw(palyer1.getPlayerShape());
        win.display();
    }

    return 0;
}
