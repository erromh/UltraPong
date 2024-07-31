#include "include/PlayerMoveUpCommand.h" 

PlayerMoveUpCommand::PlayerMoveUpCommand(Players* player) : _player(player)
{

}

void PlayerMoveUpCommand::execute()
{
    _player->moveUp();
}