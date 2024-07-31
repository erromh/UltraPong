#include "Command.h"
#include "include/Players.h"

class PlayerMoveUpCommand : public Command
{
  private:
    Players *_player;

  public:
    PlayerMoveUpCommand(Players *player);

    void execute() override;
};
