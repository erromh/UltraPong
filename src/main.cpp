#include "GlobalVaribles.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Ball/include/Ball.h"
#include "Players/include/Players.h"
#include "PlayerMoveUpCommand/include/PlayerMoveUpCommand.h"

int main()
{
    sf::RenderWindow win(sf::VideoMode(winWeight, winHeight), "Ultra Pong", sf::Style::Default);

    sf::Color color(0, 0, 255);

    float ballX = 300, ballY = 100;
    float plX = 0, plY = 350;

    Ball ball1(15, ballX, ballY);
    Players player1(plX, plY);

    PlayerMoveUpCommand upCommand(&player1);


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

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                upCommand.execute()
            }
        }

        win.clear(color);
        win.draw(ball1.getShape());
        win.draw(player1.getPlayerShape());
        win.display();
    }

    return 0;
}
