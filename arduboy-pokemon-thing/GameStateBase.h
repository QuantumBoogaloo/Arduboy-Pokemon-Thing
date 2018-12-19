#pragma once
#include <Arduboy2.h>
#include "UIContainer.h"

#include "GameStateType.h"
#include "UIStateType.h"
#include "UICommand.h"

class GameStateBase 
{
protected:
	UICommand command;
public:
	GameStateBase() {}
	virtual ~GameStateBase() {}
	
	virtual void enter(UIContainer & uiContainer)
	{
		static_cast<void>(uiContainer);
	}
	
	virtual void update(Arduboy2 & arduboy, UIContainer & uiContainer)
	{
		static_cast<void>(arduboy);
		static_cast<void>(uiContainer);
	}
	
	virtual void draw(Arduboy2 & arduboy)
	{
		static_cast<void>(arduboy);
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