#pragma once
#include <Arduboy2.h>

#include "StateMachine.h"

class Game
{
private:
	Arduboy2 arduboy;
	StateMachine states;
public:
	Game() {};
	void setup();
	void loop();
};