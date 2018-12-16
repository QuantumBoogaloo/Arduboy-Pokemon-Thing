#pragma once
#include <Arduboy2.h>

#include "UIContainer.h"
#include "GameStateBase.h"
#include "GameStateType.h"

class Game
{
private:
	Arduboy2 arduboy;
	UIContainer uiContainer;
	
	GameStateBase * state;
	GameStateType currentState = GameStateType::None;
	GameStateType nextState = GameStateType::Menu;
public:
	void begin();
	void update();
};