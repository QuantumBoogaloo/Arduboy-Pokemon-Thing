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
	while(!this->stateStack.isEmpty())
		stateDrop();
	statePush(stateNext);
}

void Game::stateDrop()
{
	if(this->stateStack.isEmpty())
		return;
	delete this->stateStack[this->stateStack.getCount() - 1];
	this->stateStack.drop();
}

void Game::statePush(const GameStateType stateNew)
{
	GameState * state = nullptr;
	
	switch(stateNew)
	{
		case GameStateType::Menu:
			state = new MainMenuState();
		break;
		
		case GameStateType::Startup:	//default case incase something catastrophic happens
		default:
			state = new StartupState();
		break;
	}
	
	this->stateStack.push(state);
}
