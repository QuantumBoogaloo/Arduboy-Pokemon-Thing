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
	
	if(uiContainer.isEmpty())
	{
		arduboy.clear();
		state->update(arduboy, uiContainer);
		state->draw(arduboy);
	}
	else
	{
		uiContainer.top().update(arduboy, uiContainer);
		uiContainer.top().draw(arduboy);
	}
	
	arduboy.setCursor(0,0);
	arduboy.print(uiContainer.getCount());
	
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
	
	if(state != nullptr)
	{
		state->enter(uiContainer);
	}
	
	currentState = nextState;
}