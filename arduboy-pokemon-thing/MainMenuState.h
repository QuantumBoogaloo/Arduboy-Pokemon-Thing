#pragma once
#include "GameStateBase.h"

class MainMenuState : public GameStateBase
{
private:
public:
	void enter(UIContainer & uiContainer);
	void update(Arduboy2 & arduboy, UIContainer & uiContainer);
	void draw(Arduboy2 & arduboy);
};