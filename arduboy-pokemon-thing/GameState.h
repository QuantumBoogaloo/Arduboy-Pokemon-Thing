#pragma once

#include "StateMachineInstruction.h"
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
	
	StateMachineInstruction stateCommandGet() const;
	void stateCommandReset();
};