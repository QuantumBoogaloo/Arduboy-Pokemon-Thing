#pragma once

#include "StateMachine.h"
#include "GameStateType.h"

class GameState
{
protected:
	StateMachine * states;
public:
	GameState() {}
	~GameState() {}
	virtual void update() {};
	virtual void draw() {};
};