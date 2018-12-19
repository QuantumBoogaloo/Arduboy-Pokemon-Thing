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
};

