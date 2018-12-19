#pragma once
#include <Arduboy2.h>
#include "UIContainer.h"

#include "GameStateType.h"
#include "UIStateType.h"
#include "UICommand.h"

class UIObjectBase : public Print
{
protected:
	UICommand command;
	StandardMessageBuffer * messageBuffer;
public:
	UIObjectBase(StandardMessageBuffer & messageBuffer)
	{
		this->messageBuffer = &messageBuffer;
	}
	
	virtual ~UIObjectBase() {}
	virtual void update(Arduboy2 & arduboy) {};
	virtual void draw(Arduboy2 & arduboy) {};
	virtual void write(uint8_t letter) {};
	UICommand & getCommand()
	{
		return this->command;
	}
	void resetCommand()
	{
		this->command = UICommand();
	}
};