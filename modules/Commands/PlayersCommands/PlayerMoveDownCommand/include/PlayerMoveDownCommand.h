#pragma once
#include "Command.h"
#include "Players.h"

#include <iostream>

class PlayerMoveDownCommand : public Command
{
  private:
    PlayerMoveDownCommand() = default;

    static PlayerMoveDownCommand *_instance;

  public:
    PlayerMoveDownCommand(const PlayerMoveDownCommand &obj) = delete;

    static PlayerMoveDownCommand *getInstance();

    void execute(Players *player);
};
