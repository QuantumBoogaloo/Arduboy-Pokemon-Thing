#pragma once
#include <Arduboy2.h>
#include "UIContainer.h"

class GameStateBase 
{
private:
public:
	GameStateBase() {}
	virtual ~GameStateBase() {}
	virtual void enter(UIContainer & uiContainer) {};
	virtual void update(Arduboy2 & arduboy, UIContainer & uiContainer) {};
	virtual void draw(Arduboy2 & arduboy) {};
};