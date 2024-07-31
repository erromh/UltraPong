#include "include/PlayerMoveUpCommand.h"

PlayerMoveUpCommand::PlayerMoveUpCommand(Players *player) : _player(player)
{
}

void PlayerMoveUpCommand::execute()
{
    std::cout << "Execute command '_player->moveUp()'\n";
    _player->moveUp();
}
