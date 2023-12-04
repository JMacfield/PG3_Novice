#pragma once

#include <Manager/ICommand.h>

class InputHandler {
public:
	ICommand* HandleInput();

	void AssignMoveRightCommandToPressKeyD();
	void AssignMoveLeftCommandToPressKeyA();

private:
	ICommand* pressKeyA_;
	ICommand* pressKeyD_;
};