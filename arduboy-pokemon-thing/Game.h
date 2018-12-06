#pragma once
#include <Arduboy2.h>
#include "Utilities/Stack.h"

#include "GameStateType.h"
#include "GameState.h"

class Game
{
private:
	Arduboy2 arduboy;
	
	Stack<GameState, 4> stateStack;
	
	GameState StateConstruct(const GameStateType state);
public:
	void setup();
	void loop();
	
	void StateChange(const GameStateType stateNext);	//kills entire stack and replaces position 0
	void PushState(const GameStateType stateNew);		//adds to stack
	void PopState();
};