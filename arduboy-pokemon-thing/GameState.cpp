#include "GameState.h"

GameStateType GameState::stateChangeCommand() const
{
	return this->stateInstruction;
}