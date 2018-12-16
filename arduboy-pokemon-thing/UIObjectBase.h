#pragma once
#include <Arduboy2.h>
#include "UIContainer.h"

class UIContainer;

class UIObjectBase
{
private:
public:
	UIObjectBase() {}
	virtual ~UIObjectBase() {}
	virtual void update(Arduboy2 & arduboy) {};
	virtual void draw(Arduboy2 & arduboy) {};
	virtual void write(uint8_t letter) {};
};