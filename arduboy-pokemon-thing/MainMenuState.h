#pragma once

#include <Arduboy2.h>
#include "GameState.h"

class MainMenuState : public GameState
{
private:
public:
	MainMenuState() {}
	~MainMenuState() {}
	void update(Arduboy2 & arduboy);
	void draw(Arduboy2 & arduboy);
};