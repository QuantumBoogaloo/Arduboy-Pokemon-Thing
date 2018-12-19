#pragma once
#include <Arduboy2.h>
#include "UIContainer.h"

#include "UIMessageBuffer.h"
#include "GameStateType.h"
#include "UIStateType.h"
#include "UICommand.h"

class UIObjectBase : public Print
{
protected:
	UICommand command;
	StandardMessageBuffer * messageBuffer;
		
	size_t write(uint8_t letter) override
	{
		messageBuffer->write(letter);
		return 0;
	}
public:
	UIObjectBase(StandardMessageBuffer & messageBuffer)
	{
		this->messageBuffer = &messageBuffer;
	}
	
	UIObjectBase();
	virtual ~UIObjectBase() {}
	
	virtual void update(Arduboy2 & arduboy)
	{
		static_cast<void>(arduboy);
	}
	
	virtual void draw(Arduboy2 & arduboy)
	{
		static_cast<void>(arduboy);
	}
	
	virtual void writeChar(uint8_t letter)
	{
		static_cast<void>(letter);
	}
	
	UICommand & getCommand()
	{
		return this->command;
	}

	void resetCommand()
	{
		this->command = UICommand();
	}
};