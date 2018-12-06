#include "Game.h"

void Game::setup()
{
	arduboy.begin();
}

void Game::loop()
{
	
}



//States
void Game::StateChange(const GameStateType stateNext)
{
	this->stateStack.clear();
	PushState(stateNext);
}

void Game::PopState()
{
	this->stateStack.drop();
}

void Game::PushState(const GameStateType stateNew)
{
	this->stateStack.push(StateConstruct(stateNew));
}
