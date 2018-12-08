#pragma once

class GameState
{
protected:
public:
	GameState() {}
	~GameState() {}
	virtual void update() {};
	virtual void draw() {};
};