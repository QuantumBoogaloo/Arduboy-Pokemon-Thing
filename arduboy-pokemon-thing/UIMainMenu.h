#pragma once

#include "UIObjectBase.h"
#include "UICommand.h"

#include "UIMenuBase.h"
#include "Data/MenuDefines.h"

class UIMainMenu : public UIObjectBase
{
private:
	UIMenuBase menu = UIMenuBase(MainMenuItems);
	
public:
	UIMainMenu(StandardMessageBuffer & messageBuffer) : UIObjectBase(messageBuffer) {}
	
	void update(Arduboy2 & arduboy)
	{
		if(arduboy.justPressed(UP_BUTTON))
		{
			menu.selectPreviousIndex();
		}
		if(arduboy.justPressed(DOWN_BUTTON))
		{
			menu.selectNextIndex();
		}
		if(arduboy.justPressed(A_BUTTON))
		{
			command = UICommand(UICommandType::Push, UIStateType::Textbox);
			print(F("holy shit this works!"));
		}
	}	
	void draw(Arduboy2 & arduboy)
	{
		for(uint8_t i = 0; i < menu.getEndIndex(); ++i)
		{
			arduboy.setCursor(0, i * 8);
			arduboy.print(menu.getString(i));
		}
	}
};