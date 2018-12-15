#include "UIContainer.h"

{
	UIObjectBase * object = nullptr;
	
	if(object != nullptr)
		this->uiStack.push(object);
}

void UIContainer::drop(void)
{
	delete this->uiStack[this->uiStack.getCount() - 1];
	this->uiStack.drop();
}

void UIContainer::dropAll(void)
{
	while(this->uiStack.getCount() > 0)
		Drop();
}