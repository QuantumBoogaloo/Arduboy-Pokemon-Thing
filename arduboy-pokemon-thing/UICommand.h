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

