#include "include/PlayerMoveDownCommand.h"

PlayerMoveDownCommand::PlayerMoveDownCommand(Players *player) : _player(player)
{
}

void PlayerMoveDownCommand::execute()
{
    std::cout << "move down command\n";
    _player->moveDown();
}
