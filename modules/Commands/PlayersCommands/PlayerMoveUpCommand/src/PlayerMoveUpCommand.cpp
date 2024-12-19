#include "PlayerMoveUpCommand.h"

PlayerMoveUpCommand *PlayerMoveUpCommand::_instanse = nullptr;

PlayerMoveUpCommand *PlayerMoveUpCommand::getInstanse()
{
    return _instanse;
}

void PlayerMoveUpCommand::execute(std::unique_ptr<Players> &player)
{
    if (player)
    {
        player->moveUp();
    }
}
