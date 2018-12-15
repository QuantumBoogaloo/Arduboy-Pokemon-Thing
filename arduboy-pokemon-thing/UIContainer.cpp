#include "UIContainer.h"

void UIContainer::push(const UIStateType type)
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
		drop();
}

UIObjectBase & UIContainer::top()
{
	//WILL BREAK when getCount() == 0
	return *(this->uiStack[this->uiStack.getCount() - 1]);
}