#include "Command.h"
#include "Players.h"

class PlayerMoveUpCommand : public Command
{
  private:
    PlayerMoveUpCommand() = default;

    static PlayerMoveUpCommand *_instanse;

  public:
    PlayerMoveUpCommand(const PlayerMoveUpCommand &obj) = delete;

    static PlayerMoveUpCommand *getInstanse();

    void execute(Players *player);
};
