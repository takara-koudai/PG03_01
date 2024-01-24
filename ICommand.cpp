#include "ICommand.h"
#include "Player.h"

ICommand::~ICommand()
{

}

void RightCommand::Exec(Player& player)
{
	player.RightMove();
}

void LeftCommand::Exec(Player& player)
{
	player.LeftMove();
}

void UpCommand::Exec(Player& player)
{
	player.UpMove();
}

void DownCommand::Exec(Player& player)
{
	player.DownMove();
}
