#pragma once

#include "StateMachineInstructionType.h"
#include "GameStateType.h"

class GameState
{
protected:
	StateMachineInstruction stateInstruction;
public:
	GameState() {}
	~GameState() {}
	virtual void update() {};
	virtual void draw() {};
	
	GameStateType stateChangeCommand() const;
};