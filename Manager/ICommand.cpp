#include "ICommand.h"

ICommand::~ICommand() {

}

void MoveRightCommand::Execute(Player& player) {
	player.MoveRight();
}

void MoveLeftCommand::Execute(Player& player) {
	player.MoveLeft();
}