#include "include/Players.h"
#include "Command_Interface/include/Command.h"

class PlayerMoveUpCommand : public Command
{
    private:
        Players *_player;

    public:
        PlayerMoveUpCommand(Players* player)
        {
        }

        void execute() override;
};