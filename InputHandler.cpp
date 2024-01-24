#include "InputHandler.h"
#include "Novice.h"

ICommand* InputHandler::HandleInput()
{
	if (Novice::CheckHitKey(DIK_D))
	{
		return presskeyD_;
	}

	if (Novice::CheckHitKey(DIK_A))
	{
		return presskeyA_;
	}

	if (Novice::CheckHitKey(DIK_S))
	{
		return presskeyS_;
	}

	if (Novice::CheckHitKey(DIK_W))
	{
		return presskeyW_;
	}

	return nullptr;
}

void InputHandler::AssignMoveLeftCommand2PressKeyA()
{
	ICommand* command = new LeftCommand();

	presskeyA_ = command;
}

void InputHandler::AssignMoveRightCommand2PressKeyD()
{
	ICommand* command = new RightCommand();

	presskeyD_ = command;
}

void InputHandler::AssignMoveUpCommand2PressKeyW()
{
	ICommand* command = new UpCommand();

	presskeyW_ = command;
}

void InputHandler::AssignMoveDownCommand2PressKeyS()
{
	ICommand* command = new DownCommand();

	presskeyS_ = command;
}
