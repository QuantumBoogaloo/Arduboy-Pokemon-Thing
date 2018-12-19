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
		uiContainer.top().update(arduboy);
		uiContainer.top().draw(arduboy);
		
		uiContainer.update();
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
void Game::processCommand(UICommand & command)
{
	switch(command.getTarget())
	{
	case UICommandTarget::State:
	{
		//only supported command in state mode;
		if(command.getCommand() == UICommandType::Change)
		{
			changeState(command.getStateReturn());
		}
	}
	break;
	case UICommandTarget::UI:
	{
		switch(command.getCommand())
		{
		case UICommandType::Drop:
			uiContainer.drop();
		break;
		case UICommandType::Push:
			uiContainer.push(command.getUIReturn());
		break;
		case UICommandType::DropAll:
			uiContainer.dropAll();
		break;
		case UICommandType::Change:
			uiContainer.drop();
			uiContainer.push(command.getUIReturn());
		break;
		default:
		break;
		}
	}
	break;
	default:
	break;
	}
}