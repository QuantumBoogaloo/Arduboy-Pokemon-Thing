#pragma once

class GameState
{
protected:
public:
	GameState() {}
	virtual void update() {};
	virtual void draw() {};
};