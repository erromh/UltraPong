#include "PlayerMoveDownCommand.h"

PlayerMoveDownCommand *PlayerMoveDownCommand::_instance = nullptr;

PlayerMoveDownCommand *PlayerMoveDownCommand::getInstance()
{
    return _instance;
}

void PlayerMoveDownCommand::execute(std::unique_ptr<Players> &player)
{
    if (player)
    {
        player->moveDown();
    }
}
