#pragma once
#include "Command.h"
#include "Players.h"

#include <iostream>
#include <memory>

class PlayerMoveDownCommand
{
  private:
    PlayerMoveDownCommand() = default;

    static PlayerMoveDownCommand *_instance;

  public:
    PlayerMoveDownCommand(const PlayerMoveDownCommand &obj) = delete;

    static PlayerMoveDownCommand *getInstance();

    void execute(Players *player);
};
