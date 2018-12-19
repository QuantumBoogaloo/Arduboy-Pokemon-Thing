#include "UIContainer.h"

void UIContainer::push(const UIStateType type)
{
	UIObjectBase * object = nullptr;
	
	switch(type)
	{
	case UIStateType::Textbox:
		object = new UITextbox();
	break;
	default:
	break;
	}
	
	if(object != nullptr)
	{
		this->typeStack.push(type);
		this->uiStack.push(object);
	}
}

void UIContainer::drop(void)
{
	delete this->uiStack[this->uiStack.getCount() - 1];
	this->uiStack.drop();
	this->typeStack.drop();
}

void UIContainer::dropAll(void)
{
	while(this->uiStack.getCount() > 0)
		drop();
}

uint8_t UIContainer::getCount() const
{
	return this->uiStack.getCount();
}

bool UIContainer::isEmpty() const
{
	return (getCount() == 0);
}

UIObjectBase & UIContainer::atIndex(const uint8_t index)
{
	//WILL BREAK when getCount() == 0
	return *(this->uiStack[index]);
}

UIObjectBase & UIContainer::top()
{
	return atIndex(getCount() - 1);
}

UIStateType UIContainer::topType()
{
	//WILL BREAK when getCount() == 0
	return (this->typeStack[getCount() - 1]);
}