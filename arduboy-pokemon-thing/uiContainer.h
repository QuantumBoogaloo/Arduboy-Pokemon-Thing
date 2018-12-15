#pragma once

#include "Utilities/Stack.h"
#include "UIObjectBase.h"

class UIContainer
{
private:
	static constexpr uint8_t stackSize = 4;
	Stack<UIObjectBase *, stackSize> uiStack;
public:
};