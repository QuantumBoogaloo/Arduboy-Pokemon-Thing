#pragma once
#include <Arduboy2.h>
#include "UIContainer.h"

class Game
{
private:
	Arduboy2 arduboy;
	UIContainer uiContainer;
public:
	void begin();
	void update();
};