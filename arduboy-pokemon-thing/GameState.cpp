#include "GameState.h"

StateMachineInstruction GameState::stateCommandGet() const
{
	return this->stateInstruction;
}

void GameState::stateCommandReset()
{
	this->stateInstruction = StateMachineInstruction();
}

void GameState::stateCommandSet(const StateMachineInstruction stateInstruction)
{
	this->stateInstruction = stateInstruction;
}