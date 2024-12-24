#include "PlayerMoveUpCommand.h"

PlayerMoveUpCommand *PlayerMoveUpCommand::_instanse = nullptr;

PlayerMoveUpCommand *PlayerMoveUpCommand::getInstanse()
{
    return _instanse;
}

void PlayerMoveUpCommand::execute(Players *player)
{
    if (player)
    {
        player->moveUp();
    }
}
