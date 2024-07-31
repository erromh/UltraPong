#pragma once
#include "Command.h"
#include "include/Players.h"
#include <iostream>

class PlayerMoveDownCommand : public Command
{
  private:
    Players *_player;

  public:
    PlayerMoveDownCommand(Players *player);

    void execute() override;
};
