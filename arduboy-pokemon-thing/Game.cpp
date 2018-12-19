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
	UICommand command;
	if(uiContainer.isEmpty())
	{
		state->update(arduboy, uiContainer);
		command = state->getCommand();
		state->resetCommand();
	}
	else
	{
		uiContainer.top().update(arduboy);
		command = uiContainer.top().getCommand();
		uiContainer.top().resetCommand();
	}
	
	arduboy.clear();
	state->draw(arduboy);
	
	for(uint8_t i = 0; i < uiContainer.getCount(); ++i)
	{
		uiContainer.atIndex(i).draw(arduboy);
	}
	
	processCommand(command);
	uiContainer.update();
	
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