#include "StartupState.h"

void StartupState::update(Arduboy2 & arduboy)
{
	if(arduboy.justPressed(A_BUTTON))
	{
		stateCommandSet(StateMachineInstruction(StateMachineInstructionType::DropAllPush, GameStateType::Menu));
	}
}

void StartupState::draw(Arduboy2 & arduboy)
{
	arduboy.print(F("STANDBY"));
}