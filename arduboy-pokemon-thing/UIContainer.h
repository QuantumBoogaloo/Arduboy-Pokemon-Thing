#pragma once

#include "Utilities/Stack.h"
#include "UIObjectBase.h"

#include "UITextbox.h"
#include "UIStateType.h"

class UIContainer : public Print
{
private:
	static constexpr uint8_t stackSize = 4;
	Stack<UIObjectBase *, stackSize> uiStack;
	Stack<UIStateType, stackSize> typeStack;
public:
	void update() {}
	
	void push(const UIStateType type);
	void drop();
	void dropAll();
	
	uint8_t getCount() const;
	bool isEmpty() const;
	
	size_t write(uint8_t letter) override;
	UIObjectBase & top();
	UIStateType topType();
};
