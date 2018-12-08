#include "GameState.h"

bool GameState::stateChanged() const
{
	return this->StateChanged;
}

GameStateType GameState::stateNext() const
{
	return this->StateNext;
}