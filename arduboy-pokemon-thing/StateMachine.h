#pragma once
#include "Utilities/Stack.h"

#include "GameStateType.h"
#include "GameState.h"
#include "StateMachineInstruction.h"

#include "MainMenuState.h"
#include "StartupState.h"

class StateMachine
{
private:
	static constexpr uint8_t StackSize = 4;
	Stack <GameState *,StackSize> stateStack;
	
	void statePush(const GameStateType stateNew);
	void stateDrop();
public:
	StateMachine() {};
	void update();
};