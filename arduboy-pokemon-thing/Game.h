#pragma once
#include <Arduboy2.h>
#include "Utilities/Stack.h"

#include "GameStateType.h"
#include "GameState.h"

#include "MainMenuState.h"
#include "StartupState.h"

class Game
{
private:
	Arduboy2 arduboy;
	
	Stack< GameState *, 4> stateStack;
public:
	void setup();
	void loop();
	
	void statePush(const GameStateType stateNew);
	void stateDrop();
	void stateDropAll();
};