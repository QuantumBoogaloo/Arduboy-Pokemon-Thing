#pragma once

#include "UIStateType.h"
#include "GameStateType.h"

enum class UICommandType
{
	None,
	Drop,
	Push,
	DropAll,
	Change,
};

enum class UICommandTarget
{
	None,
	State,
	UI,
};

class UICommand
{
private:
	UICommandType command = UICommandType::None;
	UICommandTarget target = UICommandTarget::None;
	union StateData
	{
		UIStateType uiData;
		GameStateType stateData;
	} data;
public:
	UICommand()
	{
		this->command = UICommandType::None;
		this->target = UICommandTarget::None;
	}
	UICommand(UICommandType command, UIStateType data)
	{
		this->command = command;
		this->target = UICommandTarget::UI;
		this->data.uiData = data;
	}
	UICommand(UICommandType command, GameStateType data)
	{
		this->command = command;
		this->target = UICommandTarget::State;
		this->data.stateData = data;
	}
	UICommand(UICommandType command, UICommandTarget target)
	{
		this->command = command;
		this->target = target;
	}
		
};

