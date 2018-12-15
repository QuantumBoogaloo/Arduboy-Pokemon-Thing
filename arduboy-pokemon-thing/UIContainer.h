#pragma once

#include "Utilities/Stack.h"
#include "UIObjectBase.h"

#include "UIStateType.h"

class UIContainer
{
private:
	static constexpr uint8_t stackSize = 4;
	Stack<UIObjectBase *, stackSize> uiStack;
public:
	void push(const UIStateType type);
	void drop();
	void dropAll();
	
	uint8_t getCount() const;
	bool isEmpty() const;
	
	UIObjectBase & top();
};
