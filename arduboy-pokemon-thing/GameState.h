#pragma once

#include "GameStateType.h"

class GameState
{
protected:
	GameStateType StateNext;
	bool StateChanged = false;
public:
	GameState() {}
	~GameState() {}
	virtual void update() {};
	virtual void draw() {};
	
	bool stateChanged() const;
	GameStateType stateNext() const;
};