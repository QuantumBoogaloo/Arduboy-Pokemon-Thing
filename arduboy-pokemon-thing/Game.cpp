#include "Game.h"

void Game::begin()
{
	arduboy.begin();
}

void Game::update()
{
	if(!arduboy.nextFrame())
		return;
	arduboy.pollButtons();
	
	if ((state == nullptr) || (currentState != nextState))
	{
		changeState(nextState);
	}
	
	arduboy.display();
}

void Game::changeState(const GameStateType nextState)
{
	if(state != nullptr)
	{
		delete state;
	}
	
	switch(nextState)
	{
		case GameStateType::Menu:
			state = new MainMenuState();
		break;
		default:
		break;
	}
	
}