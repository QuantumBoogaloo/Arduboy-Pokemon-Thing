#pragma once

#include <Arduboy2.h>
#include "GameState.h"

#include "GameStateType.h"
#include "StateMachineInstruction.h"

class StartupState : public GameState
{
private:
public:
	StartupState() {}
	~StartupState() {}
	void update(Arduboy2 & arduboy);
	void draw(Arduboy2 & arduboy);
};