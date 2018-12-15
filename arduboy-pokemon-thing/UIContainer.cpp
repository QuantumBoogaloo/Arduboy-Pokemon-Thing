#include "UIContainer.h"

void UIContainer::Push(const UIStateType type)
{
	UIObjectBase * object = nullptr;
	
	if(object != nullptr)
		this->uiStack.push(object);
}

void UIContainer::Drop(void)
{
}

void UIContainer::DropAll(void)
{
}