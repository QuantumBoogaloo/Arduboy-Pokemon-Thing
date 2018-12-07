#include "Game.h"

void Game::setup()
{
	arduboy.begin();
}

void Game::loop()
{
	
}



//States
void Game::stateChange(const GameStateType stateNext)
{
	this->stateStack.clear();
	pushState(stateNext);
}

void Game::popState()
{
	this->stateStack.drop();
}

void Game::pushState(const GameStateType stateNew)
{
	/*
	to:do : determine if this is this safe
	*/
	
	GameState state;
	
	switch(stateNew)
	{
		case GameStateType::Menu:
			state = MainMenuState();
		break;
		
		case GameStateType::Startup:	//default case incase something catastrophic happens
		default:
			state = StartupState();
		break;
	}
	
	this->stateStack.push(state);
}
