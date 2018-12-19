#pragma once

#include "Utilities/Stack.h"
#include "UIMessageBuffer.h"
#include "UIObjectBase.h"

#include "UIStateType.h"
#include "UITextbox.h"
#include "UIMainMenu.h"

class UIContainer 
{
private:
	static constexpr uint8_t stackSize = 4;
	
	Stack<UIObjectBase *, stackSize> uiStack;
	Stack<UIStateType, stackSize> typeStack;
	StandardMessageBuffer messageBuffer;
public:	
	void push(const UIStateType type);
	void drop();
	void dropAll();
	void update();
	
	uint8_t getCount() const;
	bool isEmpty() const;
	
	UIObjectBase & top();
	UIStateType topType();
};
