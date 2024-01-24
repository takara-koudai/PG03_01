#pragma once
#include "ICommand.h"

class InputHandler
{
public:

	ICommand* HandleInput();

	void AssignMoveLeftCommand2PressKeyA();
	void AssignMoveRightCommand2PressKeyD();
	void AssignMoveUpCommand2PressKeyW();
	void AssignMoveDownCommand2PressKeyS();


private:

	ICommand* presskeyD_;
	ICommand* presskeyA_;
	ICommand* presskeyW_;
	ICommand* presskeyS_;

};

