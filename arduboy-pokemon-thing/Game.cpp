#include "Game.h"

void Game::setup()
{
	arduboy.begin();
}

void Game::loop()
{
	
}



//States
GameState Game::StateConstruct(const GameStateType state)
{
	switch(state)
	{
		default:
			return GameState();
		break;
	}
}

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
