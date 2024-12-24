#include "PvPMode.h"

PvPMode::PvPMode()
{
    _leftPlayer = std::make_unique<Players>(LEFTPLAYERXCOORDINATE, LEFTPLAYERYCOORDINATE);
    _rightPlayer = std::make_unique<Players>(RIGHTPLAYERXCOORDINATE, RIGHTPLAYERYCOORDINATE);

    _ball = std::make_unique<Ball>();

    _exitWindow = std::make_unique<ExitWindow>();

    _moveDownCommand = PlayerMoveDownCommand::getInstance();
    _moveUpCommand = PlayerMoveUpCommand::getInstanse();
}

PvPMode &PvPMode::getInstance()
{
    static PvPMode instance;
    return instance;
}

void PvPMode::initializeEntity()
{
    if (!_moveDownCommand)
    {
        throw std::runtime_error("Command not init\n");
    }
}

void PvPMode::runStrategy(sf::RenderWindow &window)
{
    try
    {
        initializeWindow(window);

        // initializeEntity();

        while (window.isOpen())
        {
            processEvents(window);

            updateEntity();

            collisionsHandler();

            render(window);
        }
    }
    catch (const std::exception &e)
    {
        handleExeption(e);
    }
}

void PvPMode::handleExeption(const std::exception &e)
{
    std::cerr << "Error: " << e.what() << std::endl;
}

void PvPMode::render(sf::RenderWindow &window)
{
    window.clear(sf::Color(0, 0, 0));

    window.draw(_leftPlayer->getPlayerShape());
    window.draw(_rightPlayer->getPlayerShape());
    window.draw(_ball.get()->getShape());
    // window.draw(_exitWindow.get()->getShape());

    window.display();
}

void PvPMode::collisionsHandler()
{
    CollisionHandler::getInstance().ballWindowCollision(_ball.get());
    CollisionHandler::getInstance().ballPlayersCollision(_ball.get(), _leftPlayer.get(), _rightPlayer.get());
}

void PvPMode::processEvents(sf::RenderWindow &window)
{
    sf::Event event;

    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            window.close();
        }
    }
}

void PvPMode::initializeWindow(sf::RenderWindow &window)
{
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);
}

void PvPMode::updateEntity()
{
    float deltatime = _clock.restart().asSeconds();

    handlePlayerMovement(sf::Keyboard::S, sf::Keyboard::W, _leftPlayer.get());
    handlePlayerMovement(sf::Keyboard::Down, sf::Keyboard::Up, _rightPlayer.get());

    _leftPlayer->update(deltatime);
    _rightPlayer->update(deltatime);
    _ball.get()->update(deltatime);
}

void PvPMode::handlePlayerMovement(const sf::Keyboard::Key downKey, const sf::Keyboard::Key upKey, Players *player)
{
    if (sf::Keyboard::isKeyPressed(downKey))
    {
        _moveDownCommand->execute(player);

        CollisionHandler::getInstance().lowerPlayerCollision(player);
    }
    else if (sf::Keyboard::isKeyPressed(upKey))
    {
        _moveUpCommand->execute(player);

        CollisionHandler::getInstance().upperPlayerCollision(player);
    }
    else
    {
        player->stopMoving();
    }
}

PvPMode::~PvPMode()
{
}
