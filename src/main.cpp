#include "GlobalVaribles.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

#include "Ball/include/Ball.h"
#include "PlayerMoveDownCommand/include/PlayerMoveDownCommand.h"
#include "PlayerMoveUpCommand/include/PlayerMoveUpCommand.h"
#include "Players/include/Players.h"

int main()
{
    sf::RenderWindow win(sf::VideoMode(winWeight, winHeight), "Ultra Pong", sf::Style::Default);

    sf::Color color(0, 0, 255);

    float ballX = 300, ballY = 100;

    float plX = 0, plY = 350;
    float pl2X = 1670, pl2Y = 350;

    Ball ball1(15, ballX, ballY);

    Players player1(plX, plY);
    Players player2(pl2X, pl2Y);

    PlayerMoveUpCommand upCommandPl1(&player1);
    PlayerMoveUpCommand upCommandPl2(&player2);

    PlayerMoveDownCommand downCommand1(&player1);
    PlayerMoveDownCommand downCommand2(&player2);

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

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                upCommandPl1.execute();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                downCommand1.execute();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
                upCommandPl2.execute();
            }

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            {
                downCommand2.execute();
            }
        }

        win.clear(color);

        win.draw(ball1.getShape());
        win.draw(player1.getPlayerShape());
        win.draw(player2.getPlayerShape());

        win.display();
    }

    return 0;
}
