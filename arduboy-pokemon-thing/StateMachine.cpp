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

void StateMachine::update()
{
	if(this->stateStack.isEmpty())
		statePush(GameStateType::Startup);
	
	auto & stateCurrent = this->stateStack[this->stateStack.getCount() - 1];
	stateCurrent->update();
	stateCurrent->draw();
	
	StateMachineInstruction stateInstruction = stateCurrent->stateCommandGet();
	stateCurrent->stateCommandReset();
	
	switch(stateInstruction.instruction)
	{
		case StateMachineInstructionType::Push:
			statePush(stateInstruction.state);
		break;
		case StateMachineInstructionType::Drop:
			stateDrop();
		break;		
		case StateMachineInstructionType::Change:
			stateDrop();
			statePush(stateInstruction.state);
		break;
		case StateMachineInstructionType::DropAllPush:
			while(!this->stateStack.isEmpty())
				stateDrop();
			statePush(stateInstruction.state);
		break;
		case StateMachineInstructionType::None:
		default:
		break;
	}

}

