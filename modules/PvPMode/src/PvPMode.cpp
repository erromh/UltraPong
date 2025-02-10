#include "PvPMode.h"

PvPMode::PvPMode()
{
    _leftPlayer = std::make_unique<Players>(LEFTPLAYERXCOORDINATE, LEFTPLAYERYCOORDINATE);

    _rightPlayer = std::make_unique<Players>(RIGHTPLAYERXCOORDINATE, RIGHTPLAYERYCOORDINATE);

    _ball = std::make_unique<Ball>();

    _exitWindow = std::make_unique<ExitWindow>();

    _moveDownCommand = PlayerMoveDownCommand::getInstance();

    _moveUpCommand = PlayerMoveUpCommand::getInstanse();

    if (!_font.loadFromFile(_fontPath))
    {
        throw std::runtime_error("Failed to load font\n");
    }

    _leftPlayerCount.setFont(_font);
    _leftPlayerCount.setCharacterSize(COUNTCHARACTERSIZE);
    _leftPlayerCount.setFillColor(sf::Color::White);
    _leftPlayerCount.setPosition(LEFTCOUNTXPOS, COUNTYPOS);
    _leftPlayerCount.setString("0");

    _rightPlayerCount.setFont(_font);
    _rightPlayerCount.setCharacterSize(COUNTCHARACTERSIZE);
    _rightPlayerCount.setFillColor(sf::Color::White);
    _rightPlayerCount.setPosition(RIGHTCOUNTXPOS, COUNTYPOS);
    _rightPlayerCount.setString("0");
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

            checkWinner();
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

int PvPMode::checkWinner()
{
    // Change condition here !!!

    if (leftPlayerCount == 2 || rightPlayerCount == 2)
    {
        return 1;
    }

    return 0;
}

void PvPMode::render(sf::RenderWindow &window)
{
    window.clear(sf::Color(0, 0, 0));

    if (checkWinner() == 1)
    {
        showExitWindow(window);
    }
    else
    {
        window.draw(_leftPlayer->getPlayerShape());
        window.draw(_rightPlayer->getPlayerShape());
        window.draw(_ball.get()->getShape());
        window.draw(_leftPlayerCount);
        window.draw(_rightPlayerCount);
    }

    window.display();
}

void PvPMode::showExitWindow(sf::RenderWindow &window)
{
    _exitWindow.get()->showWindow(window);
}

void PvPMode::collisionsHandler()
{
    CollisionHandler::getInstance().ballWindowYCollision(_ball.get());

    if (CollisionHandler::getInstance().leftBallWindowCollision(_ball.get()) == 1)
    {
        _rightPlayerCount.setString(std::to_string(++leftPlayerCount));
    }

    if (CollisionHandler::getInstance().rightBallWindowCollision(_ball.get()) == 2)
    {
        _leftPlayerCount.setString(std::to_string(++rightPlayerCount));
    }

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
        {
            leftPlayerCount = 2;
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
