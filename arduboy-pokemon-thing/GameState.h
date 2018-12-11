#pragma once

#include <Arduboy2.h>
#include "StateMachineInstruction.h"
#include "GameStateType.h"

class GameState
{
protected:
	StateMachineInstruction stateInstruction;
public:
	GameState() {}
	virtual ~GameState() {}
	virtual void update(Arduboy2 & arduboy) {};
	virtual void draw(Arduboy2 & arduboy) {};
	
	StateMachineInstruction stateCommandGet() const;
	void stateCommandReset();
};