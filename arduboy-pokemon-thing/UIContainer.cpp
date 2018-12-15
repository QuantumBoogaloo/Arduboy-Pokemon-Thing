#include "UIContainer.h"

void UIContainer::Push(const UIStateType type)
{
	UIObjectBase * object = nullptr;
	
	if(object != nullptr)
		this->uiStack.push(object);
}

void UIContainer::Drop(void)
{
	delete this->uiStack[this->uiStack.getCount() - 1];
	this->uiStack.drop();
}

void UIContainer::DropAll(void)
{
	while(this->uiStack.getCount() > 0)
		Drop();
}