#include "StateMachine.h"

void StateMachine::statePush(const GameStateType stateNew)
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

void StateMachine::stateDrop()
{
	delete this->stateStack[this->stateStack.getCount() - 1];
	this->stateStack.drop();
}

