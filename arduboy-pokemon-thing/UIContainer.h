#pragma once

#include "Utilities/Stack.h"
#include "UIMessageBuffer.h"
#include "UIObjectBase.h"

#include "UITextbox.h"
#include "UIStateType.h"

class UIContainer 
{
private:
	static constexpr uint8_t stackSize = 4;
	Stack<UIObjectBase *, stackSize> uiStack;
	Stack<UIStateType, stackSize> typeStack;
public:
	void update() {}
	
	StandardMessageBuffer messageBuffer;
	void push(const UIStateType type);
	void drop();
	void dropAll();
	
	uint8_t getCount() const;
	bool isEmpty() const;
	
	UIObjectBase & top();
	UIStateType topType();
};
