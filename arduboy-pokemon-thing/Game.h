#pragma once
#include <Arduboy2.h>

class Game
{
private:
	Arduboy2 arduboy;
public:
	void begin();
	void update();
};